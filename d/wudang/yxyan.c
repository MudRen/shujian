// /area/jiangbei/wudang/yxyan.c ������
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", YEL"������"NOR);
        set("long", @LONG
���������䵱ɽ��ʮ�����е�һ�������Ҷ������й�������ʷ�Ͼø�ʢ����
��ʷ�ϼ��أ�����������ʿ������ڴ����С������ڵ���ʷ�����źܸߵĵ�λ��
��˵������������������ǧ�ԡ���ʷ����˵���조���������������־���ͼ��
�飬�����õ�ҩΪ���β������ó�������������
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"langmei",
                "westup" : __DIR__"wulong",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        setup();
}
