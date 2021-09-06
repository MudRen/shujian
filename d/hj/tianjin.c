// tianjin.c �쾮
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "�쾮" NOR);
        set("long", "���������������˽�����ԭ�������ǿ��쾮������Ӷ��ϵĶ���ֱ��������
�ıڹ��Ķ�������ľ��ķ�����̬���졣������һ��"HIM"����"NOR"(tiemen)��\n");
        set("no_sleep_room", 1);
        set("exits", ([
              "north" : __DIR__"mg-room1",            
        ])); 
        set("item_desc",([           
         "tiemen" : "������ϡ�ѿ���һ���죬����û��һ˿��������Ӧ�ÿ��Դ�(open)����\n", 
        ]));
        set("outdoors", "�߲�");
        setup(); 
}

void init()
{
   object me, room;
   object* obs;
   int i, count = 0;
   me = this_player();
   room = this_object();
   
   if(!present("hua hui", room)) {
          obs = deep_inventory(me);
          i = sizeof(obs);
   
          while (i--)
	        if (obs[i]->query("id")=="tu juan" 
	         || obs[i]->query("id")=="xiang shi"
	         || obs[i]->query("id")=="kuaixueshiqing tie") count++;
		
          if(count > 0){
                message_vision(HIR"ֻ����ǰ�洫��һ�������Ц������������������������ס��һǧ�ꡣ������һ������������\n"NOR, me);
                tell_object(me, HIY"\nֻ��һֻ��Ӱ���������������ǰ��\n"NOR); 
                new(__DIR__"npc/hua")->move(environment(me));        
                room->delete("exits");
          }     
   }       
   add_action("do_move","open");
}

int do_move(string arg)
{
        object room, room1;
        room1 = this_object();
        if( !arg || arg!="tiemen" ) return 0;
        if(!room1->query("exits")) return 0;
        message("vision","���ź�Ȼ������������������һ�໺���ƿ���¶��һ�����ڡ�\n", this_object() );
        set("exits/southdown", __DIR__"mg-indoor");
        if(room = load_object(__DIR__"mg-indoor")){
           room->set("exits/northup", __FILE__);
           message("vision", "���ź�Ȼ����������������¶��һ����������ڡ�\n",room );
           } 
        remove_call_out("close_door");
        call_out("close_door", 5);
        return 1;
}

void close_door()
{
        object room;
        if( !query("exits/southdown") ) return;
        message("vision","��Ȼһ�������������������ֻ����غ����ˡ�\n", this_object() );
        if(room = load_object(__DIR__"mg-indoor")){
           room->delete("exits/northup");
           message("vision", "���ź�Ȼ�����������������������ƻ�ԭ������������ס�ˡ�\n", room );
           }
        delete("exits/southdown");
}
