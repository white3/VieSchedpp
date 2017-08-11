/**
 * @file VLBI_baseline.h
 * @brief class VLBI_baseline
 *
 *
 * @author Matthias Schartner
 * @date 29.06.2017
 */

#ifndef BASELINE_H
#define BASELINE_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
namespace VieVS{
    class VLBI_baseline {
    public:
        /**
         * @brief empty default constructor
         */
        VLBI_baseline();

        /**
         * @brief constructor
         *
         * @param staid1 id of first station
         * @param staid2 id of second station
         * @param srcid id of observed source
         * @param startTime observation start time in seconds after session start
         */
        VLBI_baseline(int staid1, int staid2, int srcid, unsigned int startTime);

        /**
         * @brief default copy constructor
         *
         * @param other other baseline
         */
        VLBI_baseline(const VLBI_baseline &other) = default;

        /**
         * @brief default move constructor
         *
         * @param other other baseline
         */
        VLBI_baseline(VLBI_baseline &&other) = default;

        /**
         * @brief default copy assignment operator
         *
         * @param other other baseline
         * @return copy of other baseline
         */
        VLBI_baseline &operator=(const VLBI_baseline &other) = default;

        /**
         * @brief default move assignment operator
         *
         * @param other other baseline
         * @return moved other baseline
         */
        VLBI_baseline &operator=(VLBI_baseline &&other) = default;

        /**
         * @brief destructor
         */
        virtual ~VLBI_baseline() {}

        /**
         * @brief getter method for first station id
         *
         * @return first station id
         */
        int getStaid1() const {
            return staid1;
        }

        /**
         * @brief getter method for second station id
         *
         * @return second station id
         */
        int getStaid2() const {
            return staid2;
        }

        /**
         * @brief getter method for source id
         *
         * @return source id
         */
        int getSrcid() const {
            return srcid;
        }

        /**
         * @brief getter function for scan start time
         * @return start time in seconds from session start
         */
        unsigned int getStartTime() const {
            return startTime;
        }

//        vector<pair<string, double> > getObservedFlux() const {
//            return observedFlux;
//        }

        /**
         * @brief getter function for scan duration
         *
         * @return scan duration in seconds
         */
        unsigned int getScanDuration() const {
            return scanDuration;
        }

        /**
         * sets scan duration of this baseline
         *
         * @param scanDuration scan duration in seconds
         */
        void setScanDuration(unsigned int scanDuration) {
            VLBI_baseline::scanDuration = scanDuration;
        }

//        void setObservedFlux(const vector<pair<string, double> > &observedFlux) {
//            VLBI_baseline::observedFlux = observedFlux;
//        }

//        void setScanDuration(vector<pair<string, unsigned int> > &scanDurations);
//
//        string longestScanDurationBand();

    private:
        int staid1; ///< id of first antenna
        int staid2; ///< id of second antenna
        int srcid; ///< id of observed source
        unsigned int startTime; ///< start time of observion in seconds since session start

//        vector<pair<string, double> > observedFlux;
//        vector<pair<string, unsigned int> > scanDurations;

        unsigned int scanDuration; ///< required scan duration in seconds
    };
}
#endif /* BASELINE_H */

