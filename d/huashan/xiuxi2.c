// Room: /d/huashan/xiuxi2.c
// Date: Look 99/03/25
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������ֻ����
�����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
        	"north" : __DIR__"celang4",
	]));

        set("indoors", "��ɽ" );
        set("coor/x",90);
  set("coor/y",-40);
   set("coor/z",80);
   setup();
}



 void init()
{
	int time;
	object me;
	
	   me = this_player();
 	 time = time()- me->query("quest/zixia/time",1);
 	 
 	 if(me->query("quest/zixia/pass")) return;

                if(me->query_temp("hs/askzixia")>=2 && time>=86400 ) 
		{				
        if(random(10)==3 && random(me->query("kar"))>=25 || me->query("id")=="master" )
					{
  message_vision(HIG"$N��Ҫ���ţ�����һƳ֮�£�ֻ��½����ֱͦͦ�����ڵ��²������Ա�һ����װ���ӣ�\n"+
                    "��������������ʲô��һ����������æ��·���ӣ����Ƕ�ʦ���͵�ŵ��\n"NOR,me); 
             
 message_vision(HIM"$N�ƺ���������ϼ�ؼ�ʧ�ٵ����ܡ�\n"NOR,me);    

                    me->set_temp("hs/askzixia",3);			
                    me->set("quest/zixia/pass",1);
           
            log_file("quest/zixia",sprintf("%-18s��������ϼ�ؼ�ʧ�ٵ����ܡ�����%d����%d������%d��\n",
                     me->name(1)+"("+capitalize(getuid(me))+")",
                     me->query("kar"), 
                     me->query("int"),
                     me->query("pur")  ), me  );            
                    
						}
	
			else{
							
     message_vision(HIG"$N����������ʱ��ͻȻ�䡰������һ������г�����ֻ��½����ֱͦͦ�����ڵ��²�����\n"+
                        "��ȥ��Ȼ��ʱ��$Næ���ֵ�½����ʬ��Ļ���һ�ѣ�ȴ�������ǲ�����ϼ���š���\n"+ 
                        "$N�ڿ��ϡ����ԡ��Žǡ��εף�����Ѱ�ң�ȴ�����С���ϼ���š����ټ���\n"+
                        "$N��ÿ����ϸϸ�ҹ������Ź�Ȼ������Ҳû���ְ����ɵ�����������������Ρ�\n"NOR,me); 
        me->delete_temp("hs/askzixia");
        me->set("quest/zixia/time",time());
    
        }


 }
}



