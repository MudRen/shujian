#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��Ȥͤ");
	set("long", @LONG
ͤ�ڸ߸�����������д�ġ���Ȥ����һ�顣ͤ��װ�ξ��½�̻Ի͡���
�ܡ�Χ����ȹ���ϵ�̵��������ͼ��Ω��ΩФ���ڴ˿��Ի���ȫ԰��ɫ��
LONG
);
	set("exits", ([
	"east" : __DIR__"wenmeige",
	"northwest" :__DIR__"yanyutang",
        ]));
 	set("outdoors", "suzhou");
	set("coor/x",140);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}


