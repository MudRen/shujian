// men-tian.c ������
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"������"NOR);
       set("long", @LONG
������ɼ����������ţ�����������޴����ƺ�ϵ���һ�桰�족�ִ��졣
��ʮ����������ԭ���ӽ���������ͷ��ɣ����ܶ����˸�ʽ����װ����������
��������һ��ָ�������ǡ�
LONG);    
	set("exits", ([
		"northwest" : __DIR__"senlin-"+(1+random(8)),	
		"southwest" : __DIR__"senlin-"+(1+random(8)),
                "southeast" : __DIR__"senlin-"+(1+random(8)),
                "northeast" : __DIR__"senlin-"+(1+random(8)),
	]));           
        set("objects",([
		"/d/mingjiao/npc/dizi10" : 1,
                "/d/mingjiao/npc/dizi6" : 2,
	]));  	
        set("outdoors", "���̹�����");
        set("mj_xl", "yan");
        set("mj_xl2", 3);
        set("coor/x",-250);
  set("coor/y",230);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",230);
   set("coor/z",120);
   setup();
}

#include "mj_xunluo.h";
