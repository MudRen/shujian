// /area/jiangbei/wudang/laojun.c �Ͼ���
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", WHT"�Ͼ���"NOR);
        set("long", @LONG
�Ͼ���ʯ����������Ͼ���һ���Ͼ������˶�ׯ������������״��Ϊ��
����� ���Ͼ���ʯ�ߵ���߻���һĦ��ʯ��Ⱥ�������С�̫�����䵱����
���������ɡ���ʯ�̡���������Ӫ����ǵ�����������ס�Ļ�������Ԫʼ��
���鱦���𡢵��������Ԣ����Ҳ����Ϊ�����徳���� 
LONG
        );

        set("exits", ([
                "east" : __DIR__"fuzhen",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        setup();
}
