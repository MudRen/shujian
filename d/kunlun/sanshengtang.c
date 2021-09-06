// sanshengtang.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
         set("short", HIY"��ʥ��"NOR);
         set("long",@long
������ʥ���ˡ�������ʥ�������������ԭΪ���������ԣ�������������
������������׳������Զ�����������������ɾ������£��Ӵ���·����Ӣ
�۵ĵط�����������ʥ��Ҳֻ�����ٰ��������ˡ�
long);
         set("exits",([
             "north" : __DIR__"lang1",
             "southwest" : __DIR__"jiuqulang2",
         ]));

         set("objects",([
             CLASS_D("kunlun") + "/banshuxian.c" :   1,
             __DIR__"npc/xingfang.c" :   1,
             __DIR__"npc/kl-dizi3.c" :   1,
         ]));

         set("valid_startroom", 1);
         set("no_clean_up", 0);
         setup();
}
