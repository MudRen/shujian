// /u/beyond/hz/duanqiao.c ����
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"���Ų�ѩ"NOR);
        set("long", @LONG
����λ�ڰ׵̵Ķ��棬���������������һ���ţ�Ҳ������ѩ��Ϊ����
����֮һ������ب�ڰ׵�֮�ϣ��ڻ�ѩ����δ��ʱ��Զ��������ˮ�е�Ӱ��
���ӳ���γ����еġ����Ų�ѩ����������
LONG
        );
        set("exits", ([
            "southeast" : __DIR__"baidi",
            ]));
        set("coor/x",70);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}
