// /area/jiangbei/wudang/yuxuyan.c ������
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
������Ѩ�����������㣬�����Ҷ����洦�ɼ�����������ַ��Ħ��ʯ��
�����ܲʻ�����񡣱���������ѧ������ڡ��䵱ɽ�������м��أ�����
װ��������֮ͽ��Խ���룬����ἣ���פ���ȡ�������˼��˵����������ȡ��
����ɮ�����������Ǵ��ŷ𾭣���ɽԽ�룬���������ң���ס��������ͽ�ܴ�
�ڷ𾭡�
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"mozhen",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 1+ random(2),
        ]));

        set("no_clean_up", 0);
        set("outdoors", "�䵱");

        setup();
}
