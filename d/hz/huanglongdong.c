// /u/beyond/hz/huanglongdong.c ������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"������"NOR);
        set("long", @LONG
���߽��˻��������������ͥԺ��Բ����Ϊ������԰������ֲ������
�Ҳ�ͥԺ�ϲ������ȣ���������أ��صĶ������������ɽ����̫��ʯ�ѵ�
��ɽ��ɽ�������ֺ��С�ɽ�䲻��ȴ�ľ߷����������ȡ�
LONG
        );
        set("exits", ([
"southeast" : __DIR__"shuichi",
           "southdown" : __DIR__"shanlu",
]));
        set("coor/x",60);
  set("coor/y",-290);
   set("coor/z",0);
   setup();
}
