// /u/cool/tls/goudi.c
// 1997.2.13
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","�����ŵ�");
  set("long",@LONG
�����ǰ����ŵף����ܶ��Ǵ�ʯ��һ��С��˳�����£������в�
�ٹǺ�����Ŷ���ʧ��ˤ���ġ����ﶫ��ɽ������һƬ���֣�����ֻ
�ô��Ǳ��ϡ�
LONG);

     set("outdoors", "������");
     set("exits",([
           "eastup" : __DIR__"road5",
     ]));
     setup();
}
