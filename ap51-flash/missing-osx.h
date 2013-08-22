/*
 * Copyright (C) Open Mesh, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 3 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

#ifndef __MISSING_OSX_H__
#define __MISSING_OSX_H__

#define ETH_ALEN 6
#define ETH_HLEN 14
#define ETHERTYPE_ARP 0x0806
#define ARPOP_REQUEST 1
#define ARPOP_REPLY   2
#define ETH_P_IP       0x0800          /* Internet Protocol packet     */
#define ICMP_DEST_UNREACH  3
#define IPPORT_TFTP 69
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;

struct tcphdr {
	uint16_t source;
	uint16_t dest;
	uint32_t seq;
	uint32_t ack_seq;
	uint16_t res1:4,
		 doff:4,
		 fin:1,
		 syn:1,
		 rst:1,
		 psh:1,
		 ack:1,
		 urg:1,
		 ece:1,
		 cwr:1;
	uint16_t window;
	uint16_t check;
	uint16_t urg_ptr;
};

struct iphdr {
	unsigned int ihl:4;
	unsigned int version:4;
	u_int8_t tos;
	u_int16_t tot_len;
	u_int16_t id;
	u_int16_t frag_off;
	u_int8_t ttl;
	u_int8_t protocol;
	u_int16_t check;
	u_int32_t saddr;
	u_int32_t daddr;
};

struct udphdr {
	u_int16_t source;
	u_int16_t dest;
	u_int16_t len;
	u_int16_t check;
};

struct ether_header {
	u_int8_t  ether_dhost[ETH_ALEN];	/* destination eth addr	*/
	u_int8_t  ether_shost[ETH_ALEN];	/* source ether addr	*/
	u_int16_t ether_type;		        /* packet type ID field	*/
};

struct arphdr {
	unsigned short	ar_hrd;		/* format of hardware address	*/
	unsigned short	ar_pro;		/* format of protocol address	*/
	unsigned char	ar_hln;		/* length of hardware address	*/
	unsigned char	ar_pln;		/* length of protocol address	*/
	unsigned short	ar_op;		/* ARP opcode (command)		*/

};

struct ether_arp {
	struct  arphdr ea_hdr;          /* fixed-size header */
	u_int8_t arp_sha[ETH_ALEN];     /* sender hardware address */
	u_int8_t arp_spa[4];            /* sender protocol address */
	u_int8_t arp_tha[ETH_ALEN];     /* target hardware address */
	u_int8_t arp_tpa[4];            /* target protocol address */
};


#endif /* __MISSING_OSX_H__ */
