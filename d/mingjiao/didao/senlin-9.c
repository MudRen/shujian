// senlin-9.c ��ɼ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",MAG"��ɼ��"NOR);
       set("long", @LONG
���������̹������ϵ�һƬ��ɼ�֡���Χȫ�Ǽ�ʮ�ɸߵ���ɼ����ʵ��֦
Ҷ��һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ���һ�߽���������ɭ�֣�
ֱ����������øϿ��뿪��
LONG);    
       set("exits", ([
                "north" : __DIR__"men-tian",
                "south" : __DIR__"men-di",
                "east" : __DIR__"men-feng",
                "west" : __DIR__"men-lei",
       ]));           
       set("outdoors", "���̹�����");
       set("coor/x",-250);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}

void init()
{
       object me= this_player();
       int i= random(me->query_int());
       if( i < 10 ){
       set("exits/east", __DIR__"men-tian");
       set("exits/south", __DIR__"men-di");
       set("exits/west", __DIR__"men-feng");
       set("exits/north", __DIR__"men-lei");
       } 
       if(  i >= 10  && i < 20){
       set("exits/east", __DIR__"men-di");
       set("exits/south", __DIR__"men-feng");
       set("exits/west", __DIR__"men-lei");
       set("exits/north", __DIR__"men-tian");
       }  
       if( i >= 20  && i < 30 ){
       set("exits/east", __DIR__"men-feng");
       set("exits/south", __DIR__"men-lei");
       set("exits/west", __DIR__"men-tian");
       set("exits/north", __DIR__"men-di");
       }  
       if( i >= 30 ){
       set("exits/east", __DIR__"men-lei");
       set("exits/south", __DIR__"men-tian");
       set("exits/west", __DIR__"men-di");
       set("exits/north", __DIR__"men-feng");
       }  
}
   
