#ifndef ROCKET_PROFILE_H
#define ROCKET_PROFILE_H

// flight profile
#define _FLIGHT_MONTH                 9
#define _FLIGHT_TIME_HOUR             11
#define _FLIGHT_TIME_MINUTES          3

// rocket params
#define ROCKET_HEIGHT                 1 // in metres

#define LIFTOFF_THRESHOLD             11.0f // in ms^-2

#define DESCENT_CHECK_AMOUNT          2

#define APOGEE_CONFIRMATION_THRESHOLD 0.50f // in meters

#define ALTITUDE_CHANGE               0.600f
#define PARACHUTE_DEPLOYMENT_HEIGHT   200.0f // in meters
#define LANDING_ALTITUDE              25.00f // in meters

#endif // ROCKET_PROFILE_H