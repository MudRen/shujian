// Room: /d/emei/qianfoandd.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "ǧ���ִ��");
	set("long", @LONG
ǧ���ֵ���߹���������ׯ�ϡ�������һ������ǧ�����ƣ�����������
���ڵ��壬���з��������������У����ƾ����ޱȡ�
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"chanfang2",
  "out" : __DIR__"qianfoan",
]));
	set("objects",([
	CLASS_D("emei") + "/jing-hui" : 1,
	CLASS_D("emei") + "/wen-yin" : 1,
]));
create_door("east", "С��", "west", DOOR_CLOSED);
	setup();
}
