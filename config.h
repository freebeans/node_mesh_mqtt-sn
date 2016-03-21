/* Configurações */
#ifndef _NODE_MESH_MQTT_SN_CFG_H_
#define _NODE_MESH_MQTT_SN_CFG_H_



#define MQTT_HOST 		"aaaa::1"		/* DEVE SER UMA STRING */
#define MQTT_HOST_PORT 	1884			/* DEVE SER UM  NÚMERO */
#define MQTT_CLIENT_ID 	"node_mesh"		/* DEVE SER UMA STRING */
#define MQTT_TOPIC_PUB	"nodes"			/* DEVE SER UMA STRING */
#define MQTT_FIXED_MSG	"alive"			/* DEVE SER UMA STRING */



/* Canal que a interface sem fio deve usar (entre 11 e 26) [número] */
#define WIRELESS_CHANNEL 21
#define PANID 0xBEA1
/* PAN ID que a interface sem fio deve usar [número] */

#endif
