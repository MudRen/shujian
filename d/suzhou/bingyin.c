// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
	�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ��
�����ܡ����������������ȫ�������Χ�˹��������ƿ�����̫�
LONG
	);

	set("exits", ([
//  "south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));

 set("objects", ([
//    __DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
 __DIR__"npc/bing" : 3,
	]));
	set("coor/x",100);
  set("coor/y",-230);
   set("coor/z",0);
   set("incity",1);
	setup();
}


