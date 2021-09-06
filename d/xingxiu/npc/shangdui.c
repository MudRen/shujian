//snowman 28/02/98
#include <ansi.h>
inherit ITEM;

mapping *dest = ({
([ "name":"yilihe",
           "context": ({
		"/d/xingxiu/yili/yili","/d/xingxiu/shanjiao","/d/xingxiu/silk9","/d/xingxiu/silk8","/d/xingxiu/silk7",
		"/d/xingxiu/silk6","/d/xingxiu/silk5","/d/xingxiu/silk4","/d/xingxiu/silk3","/d/xingxiu/silk2",
		"/d/xingxiu/silk1","/d/xingxiu/silk",
})]),

([ "name":"jygw",
           "context": ({
		"/d/xingxiu/silk","/d/xingxiu/silk1","/d/xingxiu/silk2","/d/xingxiu/silk3","/d/xingxiu/silk4",
		"/d/xingxiu/silk5","/d/xingxiu/silk6","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk9",
		"/d/xingxiu/shanjiao","/d/xingxiu/yili/yili",
})]),
([ "name":"silk",
           "context": ({
		"/d/xingxiu/silk1","/d/xingxiu/silk2","/d/xingxiu/silk3","/d/xingxiu/silk4","/d/xingxiu/silk5a",
		"/d/xingxiu/silk7a","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk9","/d/xingxiu/shanjiao",
		"/d/xingxiu/yili/yili",
})]),
([ "name":"silk1b",
           "context": ({
		"/d/xingxiu/silk1","/d/xingxiu/silk2","/d/xingxiu/silk3","/d/xingxiu/silk3a","/d/xingxiu/silk3b",
		"/d/xingxiu/silk3c","/d/xingxiu/silk7a","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk10",
		"/d/xingxiu/yili/yili",
})]),
([ "name":"yili",
           "context": ({
		"/d/xingxiu/silk10","/d/xingxiu/silk8","/d/xingxiu/silk7","/d/xingxiu/silk7a","/d/xingxiu/silk5a",
		"/d/xingxiu/silk4","/d/xingxiu/silk3","/d/xingxiu/silk2","/d/xingxiu/silk1","/d/xingxiu/silk1a",
		"/d/xingxiu/silk1b","/d/xingxiu/silk",
})]),
([ "name":"shanjiao",
           "context": ({
		"/d/xingxiu/silk9","/d/xingxiu/silk8","/d/xingxiu/silk7","/d/xingxiu/silk7a","/d/xingxiu/silk3c",
		"/d/xingxiu/silk3b","/d/xingxiu/silk3a","/d/xingxiu/silk3","/d/xingxiu/silk2","/d/xingxiu/silk1",
		"/d/xingxiu/silk",
})]),
([ "name":"silk5b",
           "context": ({
		"/d/xingxiu/silk5","/d/xingxiu/silk5a","/d/xingxiu/silk7a","/d/xingxiu/silk3c","/d/xingxiu/silk3b",
		"/d/xingxiu/silk3a","/d/xingxiu/silk3","/d/xingxiu/silk2","/d/xingxiu/silk1","/d/xingxiu/silk1a",
		"/d/xingxiu/silk1b","/d/xingxiu/silk",
})]),
([ "name":"silk3a",
           "context": ({
		"/d/xingxiu/silk3b","/d/xingxiu/silk3c","/d/xingxiu/silk7a","/d/xingxiu/silk5a","/d/xingxiu/silk5",
		"/d/xingxiu/silk6","/d/xingxiu/silk7","/d/xingxiu/silk8","/d/xingxiu/silk9","/d/xingxiu/shanjiao",
		"/d/xingxiu/yili/yili",
})]),
([ "name":"silk8",
           "context": ({
		"/d/xingxiu/silk7","/d/xingxiu/silk6","/d/xingxiu/silk5","/d/xingxiu/silk5a","/d/xingxiu/silk7a",
		"/d/xingxiu/silk3c","/d/xingxiu/silk3b","/d/xingxiu/silk3a","/d/xingxiu/silk3","/d/xingxiu/silk2",
		"/d/xingxiu/silk1","/d/xingxiu/silk",
})]),
});

void create()
{
	set_name("�����̶�", ({ "shangdui"}));
	set("unit", "ֻ");
	set("location", 1);
	set_weight(900000);
	set("long", "һֻԶ�������������̶ӣ����ձ��϶����˻��\n"+
			"��������������һЩ�����������ǱȽ���Ҫ�Ķ���������\n");
	set("no_get", 1);
	set("no_drop", 1);
}

void init()
{
  	call_out("destroying", 20, this_object());  
  	add_action("do_rob", "qiang");
}

int do_rob()
{
   	object me, ob;   
   	string arg;
   	int stage, i;
   	
   	me = this_player();
   	ob = this_object();
   	stage = 0;
   	i = sizeof(dest);
   	arg = query("arg");

   	if(!living(me)) return 0;
   	
	if( query_temp("robber") != me ) 
		return notify_fail("������������ҹ��컯��֮�������̶ӣ����±�����������\n");

	if( objectp(present("hubiao biaoshi", environment(me))) )
		return notify_fail("������ʦ�����书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  

	message_vision(HIY"$N����$n���һ��������"+me->name()+"�ڴˣ��������ǵ�Ǯ������\n"NOR, me, ob);
	me->set_temp("xx_rob", 1);
	if(!ob->query("going")){
		while (i--) if (arg == dest[i]["name"]) break;
		remove_call_out("go_stage");
		ob->set("f", 6 * (me->query_temp("xx2/j")+1));
		call_out("go_stage", 1, ob, stage, i, sizeof(dest[i]["context"]), me);   
		ob->set("going", 1);
	}
	remove_call_out("make_bs");
	call_out("make_bs", 1, me, ob); 
	return 1;     
}

void make_bs(object me, object ob)
{
   	object obj, obj1;
    	int j;
   	j = me->query_temp("xx2/j");
   	if(j>0){        
         	obj = new(__DIR__"biaoshi");
         	obj->move(environment(me));
         	obj->do_copy(me);
         	obj1 = new(__DIR__"biaoshi");
         	obj1->move(environment(me));
         	obj1->do_copy(me);
         	me->add_temp("xx2/j", -1);
         	return;      
        }
        
   	else{
       		message_vision(HIW"$N���Ѿ����˱�������$n����в�£�ֻ��ͣ���������������Ĳ���ԹԵ����ϣ�\n"NOR, ob, me);    
       		obj=new("/d/xingxiu/obj/red");
       		obj->move(me);
       		obj->set("owner", me->query("id"));
       		me->add("shen", -(me->query("combat_exp")/20));
       		me->delete_temp("xx_rob");
       		message_vision("$N�������գ�ת������Сɽ��Ͳ����ˡ�\n", ob);
       		destruct(ob);
       }       
}

void go_stage(object me, int stage, int i, int size, object player)
{
   	object where;
   	int f = me->query("f");
   	
   	if(stage < size && objectp(player)) {
     		message_vision(HIY"$N�Ҵ�ææ������פ���Ĺؿڷ�����ȥ��\n"NOR, me);
     		me->move(dest[i]["context"][stage]);
     		message_vision(HIY"$N�Ҵ�ææ�ر��˹�����\n"NOR, me);
     		where = environment(me); 
     		tell_object(player, HIM+me->query("name")+"����������"+(string)where->query("short")+HIM"һ����\n"NOR);
     		call_out("go_stage", f, me, ++stage, i, size, player);
     	}
   	else {    
   		if(objectp(player)){
     			tell_object(player, HIM+me->query("name")+HIM"�ɹ����ӽ��˳���\n"NOR);
     			player->delete_temp("xx2");
     			player->delete_temp("xx_rob");
     		}
     		
     		message_vision(MAG"\n$Nת�����У��ڹٱ��Ļ������뿪�ˡ�\n"NOR,me);      
     		destruct(me);
     	}
}

void destroying(object me, int i)
{
	if( i ){
		message_vision("$N�������գ�ת������Сɽ��Ͳ����ˡ�\n", me);       
       		destruct(me);
       		return;
       	}
       	
   	if(!me->query("going")){
       		message_vision("$N�������գ�ת������Сɽ��Ͳ����ˡ�\n", me);       
       		destruct(me);
       		return;
       	}
  	else call_out("destroying", 450, me, 1);
}
