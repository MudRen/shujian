// dbshan.c ��ɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ɽ"NOR);
        set("long", @LONG
���ɽ���չ�������·������۵Ĺ�â���Ե�ʮ�����������ﵽ�����Ǳ�
ѩ����ɽ�Ĵ���½����֮ɽ��һ����ȥ��������ɣ��ݳ���ʮ�ɣ���ɽ��
�������������в�ʱ�м���С����������Ʈ����
LONG);  
        set("outdoors", "����");
        set("exits", ([  
              "west" : __DIR__"dbshan",
        ]));

        setup();
}
