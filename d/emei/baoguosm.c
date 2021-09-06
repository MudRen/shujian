// Room: /d/emei/baoguosm.c

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
	set("short", "������ɽ��");
	set("long", @LONG
������Ϊ���ҳ���֮�Ż���ɽ��(gate)����һ����ҡ������骻�������
����ӳ���ɴ�һ·�����Ͽ�ʼ�Ƕ���ɽ��������ɽ��һ�������ʯ��·��
LONG
	);
	set("outdoors", "��üɽ");
	set("item_desc",([
	"gate" :  HIW "\t\t\t   �աաաաաաաաաաաաաաաա�
		�  ���     �աա��������������������������ա�
����������������           �աա������������������¡������ա�
		 ����      �աա��������������������������ա�
             ��������      �աաաաաաաաաաաաաաաա�\n" NOR
]));
	set("exits", ([ 
	  "northdown" : __DIR__"qingshijie",
	  "west" : __DIR__"baoguosi",
]));

	set("coor/x",-180);
  set("coor/y",-120);
   set("coor/z",10);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west" && is_wanted(me))
		return 0;
	return :: valid_leave(me, dir);
}
