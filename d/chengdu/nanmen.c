// /d/chengdu/xiaonanmen.c
// By Jpei

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "С����");
	set("long", @LONG
�����ǳɶ����ϲ��ţ���ר�ſ����ǽ��İ������ͻ�������ǵġ������
Ҫ��ᣬ���Դ��������¡����ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"north" : __DIR__"nancejie2",
                "south" : "/d/dali/shanlu2",
	]));
        set("outdoors", "�ɶ�");
	set("incity",1);
	setup();
}

string look_gaoshi()
{
 	return FINGER_D->get_killer() + "\n���ݴ�ʷ\n˾��Զ\n";
}

