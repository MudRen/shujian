 // daritang

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY "���շ���"NOR);
        set("long",@LONG
����һ��������ΰ�ķ��ã������������Ŵ������������ı��϶�����
�����ȹ�ģ��С�ķ�����������ʮ������ӡ����ϵʹ���ׯ�����¡�һ����
¯���������ƣ�����������¯ǰ������һλ�뷢ȫ�׵���ɮ���૵���ƺ�
   ��������ʲô��
LONG);
       set("exits", ([
        "west" : __DIR__"luoweitang"
          ]));
         set("objects", ([
"/d/xueshan/npc/huofo.c" : 1,
             ]));
          setup();
   
}
