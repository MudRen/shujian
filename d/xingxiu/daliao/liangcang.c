inherit ROOM;
#include <ansi.h>
int do_jump(string arg);
int do_dianhuo(string arg);
void create()
{
    set("short", "���");
    set("long", @LONG
���������ɹŴ���Ķ���֮������ν����δ�����������У�
�������ʳ�Ͳ��϶ѻ���ɽ��һ�Ӷ�Ѳ�߱������������䱸
ɭ�ϡ�
LONG);
	set("quest",1);
	set("exits", ([
		//"west" : __DIR__"sleep_room",
			"south" : __DIR__"zhongying",
        ]));
    setup();
}



int valid_leave(object me, string dir)
{
  if(present("liao bing",environment(me)))  return notify_fail("�ɱ�һ�ѽ�����ס�������ܣ�\n" );
  return ::valid_leave(me, dir);
}
void init()
{
  object me,obj;
  me = this_player();
  if(me->query_condition("killer"))
  {
   message_vision(HIC"\nͻȻ$N�ƺ���Ѫ��Щ��˳������һ����������ȥ��\n"NOR,me); 
   tell_object(me,HIR"��ͻȻ�е�һ�������������㣬˲����ʧȥ֪����\n"NOR);
   tell_room(environment(me),HIR"\nֻ��������ͻȻ����һ���Ѷ���"+ me->name()+ "һͷ������ȥ��˲����ʧ��\n"NOR, ({}));
   me->move(__DIR__"shanlu1"); 
   tell_room(environment(me), HIR"\n����У��ƺ�һ���˵����������㶨��һ����Ȼ��"+ me->name()+ "��\n"NOR, ({}));
   me->unconcious();
   return;
  }
  add_action("do_jump", ({"jump","tiao"}));
  if(!me->query("quest/�����˲�/���ɾ�Ԯƪ/start")) return;
  if(me->query("quest/�����˲�/���ɾ�Ԯƪ/over")) return; 
  if(!me->query_temp("quest/�����˲�/���ɾ�Ԯƪ/godaliao")) return; 
  

  obj=new(__DIR__"npc/liaobing");
  obj->set("teamleader",1);
  obj->set("fight_id",me->query("id"));
  obj->move(environment(me)); 
  add_action("do_dianhuo", ({"dianhuo","burn"}));
}
int do_jump(string arg)
{
	object me;
	me = this_player();
	message_vision(HIC"$N��׼��ǽ��һ�����ݣ�һԾ���ϣ�˳������������һ�㣬������Ʈ����ߡ�\n"NOR, me);
	me->move("/d/xingxiu/daliao/shulin");
	message_vision(HIC"$NһԾ���𣬻������ܣ����ﾹȻ������Ӫ����ǰ��Ƭ���֡�\n"NOR, me);
	me->start_busy(1);
	return 1;
} 
int do_dianhuo(string arg)
{
	object me, ob,*obj;
	int i;
	me = this_player();
	ob = this_object();
	if (!me) return 0;
	if(!me->query_temp("quest/�����˲�/���ɾ�Ԯƪ/godaliao")) return 0; 
	if (present("liao bing", ob))
		return notify_fail("�ɱ���������Ƚ�����ɱ���˵��\n");
	if (me->is_busy() || !arg )
		return notify_fail("��ȵ��������ʲô��˵��\n");    
	if (arg!="liang cao" && arg!="liangcao" && arg!="cao" )
		return notify_fail("��ȵ��������ʲô��˵��\n"); 
	if(me->query_temp("quest/�����˲�/���ɾ�Ԯƪ/dianhuo"))
		return notify_fail(HIR"�����Ѿ��������Ͽ��뿪����ȥ������塣\n"NOR);    

	//ֻ��һ������
	obj = users();
	i = sizeof(obj);
	while(i--) {
		if ( obj[i]->query_temp("quest/�����˲�/���ɾ�Ԯƪ/dianhuo") && obj[i]!=me) 
		{
			me->delete_temp("quest/�����˲�");
			me->delete_temp("quest/busy");//�����ͻ��־ȡ��
			me->delete("quest/�����˲�/time");
			me->delete("quest/�����˲�/combat_exp");
			me->move(__DIR__"shanlu1"); 
			tell_object(me,HIR"�Ѿ���"+obj[i]->query("name")+RANK_D->query_respect(obj[i]) +"���Ӫ��ȥ�ˣ�����Ҫ���ˡ�\n"NOR);
			log_file("quest/TLBB", sprintf("%s(%s)��������𣬵���%s(%s)��ͻʧ�ܡ����飺%d��\n", me->name(1),me->query("id"), obj[i]->name(1),obj[i]->query("id"), me->query("combat_exp")) ); 
			return 1;  
		}
	}
	message_vision(HIC"\n$N����ת����������������һ�ѻ�Ѹ�ٴܵ�����һ�����䣬����������У�����ˮ������ˮ����������Ȼ��Ӫ������һ�Ż��ң�\n"
		             +"$NֻҪ����û���ɱ��ĵط�������һ�ѻ���ʱ���������߰˸���ͷ��\n"NOR, me);
	message_vision(HIY"\n$N�����������̳�������������ɱ�׷����Ѷ�š�$N��ͷһ�ݣ����ǸϿ��뿪��ȥӪ������úá� \n\n"NOR, me);
	log_file("quest/TLBB", sprintf("%s(%s)���ɵ��ɹ������飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) ); 
	me->set_temp("quest/�����˲�/���ɾ�Ԯƪ/dianhuo",1);
	me->start_busy(1);
	return 1;
} 
