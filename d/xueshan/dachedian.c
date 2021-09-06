// Room: dachedian.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "�вƴ󳵵�");
	set("long", @LONG
����һ��󳵵꣬�м�һ����Ժ�ӣ�ͣ�˲��������������Ƴ�֮������乤
�ߡ�ӭ��һ������������ƻ�ͨ����һ�������ӵ��������˳������ű����Ÿ���
��(sign)������һ�����ǣ�����Գ������ӡ������⻹������ͷ�ټ������ա�
���ֿ����ǳ������������ڵģ���ʱ���˶��ŷ����߽�������ȥ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"jiedao1",
                "enter" : __DIR__"zhengfang",
	]));

        set("item_desc",([
           "sign" : 
"ͨ��һҹ�����������Ʋ����㡣����������ʧ�Ų����𡣲����շ���ѡ�\n",     
           ]));
        set("no_sleep_room",1);
        set("outdoors", "ѩɽ");
        set("objects",([__DIR__"npc/lizhaocai" : 1]));
	set("coor/x",-210);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "enter" && is_wanted(me))
		return 0;

	if ( !me->query_temp("rent_paid") && dir == "enter" )
		return notify_fail("վס����ס�����Ǯ��\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
