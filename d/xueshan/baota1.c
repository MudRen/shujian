 // baota01.c ����
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY "����������"NOR);
        set("long",@LONG
��������ӭ����һ���˽������������߾Ų㣬�������渡���з��裬����
�и��ƻ��ơ����ǹҷ��壬����嶯����������ö������б�������( tower)
Ϊ��¥ʽ������ƽ̨������Χ��ʯ�������ͱ��£����ڲ�ͬ��
LONG);
        set("exits",([
                "out": __DIR__ "lingtalin"
        ]));
	set("item_desc", ([
	  "tower" : "�����濴��ȥ��ֻ��������������������������ס�ˡ�\n",
	]));
        setup();
}
