// yugang.c �������
// Lklv 2001.9.11
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"�����ͷ"NOR);
	set("long", @LONG
���Ǹ��ݵ�һ����ۣ�����ͣ�����洬������������Ŵ󵣴󵣵�����
�ţ�������㻹���ʱĻ�������Զ����ʮ������ؤ�����ڴ���ɹ̫��������
��������ڡ������м����л������ϻ��������������ڴ���
LONG
	);
	set("outdoors","����");

	set("exits", ([
		"enter" : __DIR__"yuchuan1",
		"west" :  __DIR__"haigang",
		"south" : __DIR__"yuchuan1",
        ]));

	set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
                CLASS_D("gaibang/zfdizi") : 1,
	]));

	setup();
}
