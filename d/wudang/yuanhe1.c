// /area/jiangbei/wudang/yuanhe1.c Ԫ�͹۴��
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"Ԫ�͹۴��"NOR);
        set("long", @LONG
Ԫ�͹۵Ĵ��ڸ�̨֮�ϣ��Ե�ׯ�����¡�����ڣ����������������
�����Ƕ��������ϵ۵Ļ�����١��������ŵ����������ף���ִ��޵�����
�١�����ٳ�����Ŀ����ò��������в�˳����������ߣ�����������������
֮�ơ�����������������������Ϊ���ϡ��˼�ľ���֮��
LONG
        );

        set("exits", ([
                "west" : __DIR__"yuanhe",
        ]));

        set("no_clean_up", 0);
        setup();
}
