// Room: /d/huashan/qingke.c
// Date: Look 99/03/25

#include <wanted.h>

inherit ROOM;

void create()
{
	set("short", "���ƺ");
	set("long", @LONG
�߹���᫵�ʮ���̣��������ţ��͵������ƺ�����ƺ��һɽ����أ���
����Ϊƽ̹�������￪ʼ����ɽ��·������ԭ�������ʯ�ס�������һ���ʯ
��·����ʯ��������ʯ������ȥɽ�����գ��ο����ˣ��͸û�ͷ�ˡ�
����ԶԶ����һ��ССʯͤ�����Ƕ���ͤ�ˡ��ഫ��̫���뻪��������������
�ˣ�����ɽ��Ϊ��ע����̫�����ˣ��Ӵ˻�ɽ�ϵ����ؾͲ������Ǯ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shaluo",
		"eastup" : __DIR__"qianchi",
	]));

	set("objects", ([ 
		__DIR__"npc/haoke" : 1,
	]));

	set("outdoors", "��ɽ" );

	set("coor/x",50);
  set("coor/y",80);
   set("coor/z",10);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "eastup" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
