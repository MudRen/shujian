#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"���ֵ�"NOR);
        set("long",@LONG
�������ù�ģ��С�����������ƣ������������������֣����ڹ���
������޺������������£���Ц�ڴ󿪣���б�����ţ���ŭĿ���ӣ�
������ͬ�������Ͷ��������޺������������Լ���Դ��
LONG);       
        set("exits", ([
                "west" : __DIR__"yz3",
                "south" : __DIR__"ytd",
	]));

        set("coor/x",-340);
  set("coor/y",-290);
   set("coor/z",20);
   setup();
}