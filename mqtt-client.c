#include <string.h>
#include "net/ipv6/addr.h"
#include "MQTTSNPacket.h"
#include "MQTTSNConnect.h"
#include "config.h"

extern void udp_envia(ipv6_addr_t addr, char *data, int datasize);

int mqtt_send(ipv6_addr_t addr, char * topicname, unsigned char * msg)
{
	unsigned char buf[200];
	int buflen = sizeof(buf);
	MQTTSN_topicid topic;

	int msglen = strlen((char*)msg);
	int len = 0, dup = 0, qos = 0, retained = 0, packetid = 0;
	
	MQTTSNPacket_connectData options = MQTTSNPacket_connectData_initializer;

	options.clientID.cstring = MQTT_CLIENT_ID;
	len = MQTTSNSerialize_connect(buf, buflen, &options);
	
	// enviar buf, tamanho len, host MQTT_HOST, porta MQTT_HOST_PORT
	udp_envia(addr, (char *) buf, len);
	

	topic.type = MQTTSN_TOPIC_TYPE_NORMAL;
	topic.data.long_.name = topicname;
	topic.data.long_.len = strlen(topicname);
	len = MQTTSNSerialize_publish(buf, buflen - len, dup, qos, retained, packetid,
			topic, msg, msglen);
			
	// enviar buf, tamanho len, host MQTT_HOST, porta MQTT_HOST_PORT
	udp_envia(addr, (char *) buf, len);

	return 0;
}
