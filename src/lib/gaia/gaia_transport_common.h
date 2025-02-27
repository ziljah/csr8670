/*****************************************************************
Copyright (C) Cambridge Silicon Radio Ltd. 2011-2014
*/

#include "gaia_private.h"

#ifndef _GAIA_TRANSPORT_COMMON_H
#define _GAIA_TRANSPORT_COMMON_H

/*! @brief Utility function to send a GAIA_CONNECT_CFM message to client task.
 *
 *  @param transport The gaia transport on which the event occurred.
 *  @param success Boolean indicating success (TRUE) or failure (FALSE) of connection attempt.
 */
void gaiaTransportCommonSendGaiaConnectCfm(gaia_transport* transport, bool success);

/*! @brief Utility function to send a GAIA_CONNECT_IND message to client task.
 *
 *  @param transport The gaia transport on which the event occurred.
 *  @param success Boolean indicating success (TRUE) or failure (FALSE) of connection attempt.
 */
void gaiaTransportCommonSendGaiaConnectInd(gaia_transport* transport, bool success);

/*! @brief Utility function to send a GAIA_DISCONNECT_IND message to client task.
 *
 *  @param transport The gaia transport on which the event occurred.
 */
void gaiaTransportCommonSendGaiaDisconnectInd(gaia_transport* transport);

/*! @brief Utility function to send a GAIA_DISCONNECT_CFM message to client task.
 *
 *  @param transport The gaia transport on which the event occurred.
 */
void gaiaTransportCommonSendGaiaDisconnectCfm(gaia_transport* transport);

/*! @brief Utility function to send a GAIA_SEND_PACKET_CFM message to client task.
 *
 *  @param transport The gaia transport on which the event occurred.
 *  @param packet Pointer to the packet data that was transmitted.
 *  @param success Boolean indicating success or failure of Gaia command transmission.
 */
void gaiaTransportCommonSendGaiaSendPacketCfm(gaia_transport *transport, uint8 *packet, bool success);

/*! @brief Utility function to send a GAIA_START_SERVICE_CFM message to client task.
 *
 *  @param transport_type The transport type over which the service runs
 *  @param transport The transport instance over which the service runs. May be NULL for some transports which are configured on connection, such as SPP. Will also be NULL if the 'success' parameter indicates a failure to start the service.
 *  @param success Boolean indicating success or failure of the GaiaStartService request
 */
void gaiaTransportCommonSendGaiaStartServiceCfm(gaia_transport_type transport_type, gaia_transport* transport, bool success);

/*! @brief Cleanup battery and RSSI threshold state for a given transport.
 
    Used once a Gaia transport has closed, as we no longer need to perform the
    checking or resend the timer messages.
*/
void gaiaTransportCommonCleanupThresholdState(gaia_transport *transport);

#endif /* _GAIA_TRANSPORT_COMMON_H */
