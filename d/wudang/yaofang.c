// /d/wudang/yaofang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",YEL"ҩ��"NOR);
        set("long", @LONG
�����䵱ɽ���µ�һ��Сҩ����һ���䵱��ͯ���ڲ�ͣ���ŷ��䡣���ݵ�
ǽ������һ��ֽ��paper)���м���һ����¯(lu)������ɢ����ŨŨ��ҩζ����
�������˰���ʲô��ҩ��
LONG
        );
        set("no_fight",1);

        set("objects",([
           __DIR__"danlu/lu" : 1,
                __DIR__"npc/daotong2" : 1,
        ]));

        set("exits", ([
           "east" : __DIR__"zoulang3",
        ]));

        set("item_desc", ([
           "paper": "��ҩ�������£�\n"
"\n\t\t�� �򿪸���"HIC"<--->(open lid)\n"NOR
"\t\t�� ���ҩ��"HIC"<--->(add ҩ���� in lu)\n"NOR
"\t\t�� �����ˮ"HIC"<--->(pour ���� in lu)\n"NOR
"\t\t�� �رո���"HIC"<--->(close lid)\n"NOR
"\t\t�� ��ȼ����"HIC"<--->(dianhuo)\n"NOR
"\t\t�� ��ȼ���"HIC"<--->(burn coal)\n"NOR
"\t\t�� �尾ҩ��"HIC"<--->(aoyao)\n"NOR
"\t\t�� ����¯"HIC"<--->(miehuo)\n"NOR
"\t\t�� ȡ��ҩ��"HIC"<--->(qu ҩ���� from lu)\n"NOR,
        ]));

        setup();
}
