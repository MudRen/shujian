// dongkou.c
// By River 98/09
inherit ROOM;
#include <ansi.h>
void create()
{
         set("short", HIY"����"NOR);
         set("long", @LONG
������һ����ʱ�̣�Խ����ǰԽ���������һ��ɽ�������˳�����������
��ҫ�ۣ�Ũ���ѵأ����⸡�����������ؼ����ա�ԭ����ɽ����������ɽɽ��
һ����Ϊ��Ƨ�����ڡ�
LONG
        );

         set("exits", ([                
                "out" : __DIR__"shanxia",  	
         ]));

         set("outdoors", "��Ĺ");

         setup();
}
