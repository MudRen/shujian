// /d/shaolin/qxdian.c ���ĵ�
#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",HIW"���ĵ�"NOR);
          set("long",@long
������һ���տ��Ĵ�����湩���ż�����񣬵��аڷ��ż������ţ�
������ܸ�װǶ��һ�ŵ�ľ�Ƴ���������͸�������������յĴ��һ
Ƭ��⡣�����󳪴���ʹ��������¹���������ȫ����
long);
          set("exits",([
              "west" :  __DIR__"dabeidia",
]));
          setup();
}


