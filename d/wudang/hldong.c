// /area/jiangbei/wudang/hldong.c ������
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"������"NOR);
        set("long", @LONG
���������䵱�����ͨ���𶥵�·�ϣ�λ���ϸǷ�����֮�С����ڿ�����
����������ʪ���ļ�������ˬ������������֮ʿ����֮�ء�����ʵ������
һ����Ȼ�����ݣ�����������֮ʿ���޽��������������˻���������ҩ
�����Ȫͤ�Ƚ�����ʹ֮���������غ����ĵ�ɫ�ʡ�
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"gsdao6",
                "southup" : __DIR__"taihe",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/youke" : 1,
        ]));

        set("outdoors", "�䵱");

        setup();
}
