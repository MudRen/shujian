// /d/xingxiu/silk3.c
//tangfeng@SJ 2004

#include <ansi.h>
inherit ROOM;
#include <wanted.h>

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"

void create()
{
        set("short", HIM"��Ħ��"NOR);
        set("long", @LONG
��Ħ����������������Χɽ�ƶ��ͣ���ɽ���ţ�һ����������Ͽ����̶��
Ԩ��Ī�⡣�״��л�����̶�ɳ�����������̶��̶���Ħ�³ɱ��������漣��
�ʴ��پ������������������˿��쾮���Ĺ��̡��������ǳ��ɽ����������
ʯ�š�
LONG);
        set("outdoors", "yili");
           set("quest",1);

        set("exits", ([
                "eastdown" : __DIR__"silk2",
                "westdown" : __DIR__"silk4",
                "north" : __DIR__"silk3a",
        ]));

        set("coor/x",-250);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-250);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-250);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}

void init()
{
	object me = this_player();
	if (me->query(QUESTDIR3+"start")&&me->query_temp(QUESTDIR3+"askxiao") && !me->query_temp(QUESTDIR3+"lookcliff")&& !me->query(QUESTDIR3+"over")) {
		add_action("do_jump", ({"jump", "tiao"}));
		add_action("do_look", ({"look"}));
	}
        if ((me->query(QUESTDIR3+"good")&&me->query_temp(QUESTDIR4+"dagouzhen") &&me->query_temp(QUESTDIR4+"shaolinzhen")&&!me->query(QUESTDIR4+"over"))||(me->query(QUESTDIR4+"start")&&!me->query(QUESTDIR4+"over"))) {
		add_action("do_da", ({"da", "answer"}));
    if (localtime(TIME_TICK)[2] <= 2) tell_object(me,HIB"����ˣ����������һƬ�����ֲ�����ָ������ҹϮ��Ӫ�ĺ�ʱ����ô��Ӧ���˻�û���أ�\n"NOR); 
		add_action("do_han", ({"han", "yell"}));
	}
}
int do_look(string arg)
{
	object me = this_player();

	if (me->query(QUESTDIR3+"start")&&me->query_temp(QUESTDIR3+"askxiao") && !me->query_temp(QUESTDIR3+"lookcliff")&& !me->query(QUESTDIR3+"over")) {
	 if (!arg) {
		set("long", @LONG
��Ħ����������������Χɽ�ƶ��ͣ���ɽ���ţ�һ����������Ͽ����̶��
Ԩ��Ī�⡣�״��л�����̶�ɳ�����������̶��̶���Ħ�³ɱ��������漣��
�ʴ��پ������������������˿��쾮���Ĺ��̡��������ǳ��ɽ����������
ʯ�š�ɽ�ڣ�cliff����ԶԶ��ȥһ��ط������ޱȣ��ƺ�������Ծ��ȥ��
LONG
);
		me->look(arg);
	 }
	 else if (arg == "cliff") {
		tell_object(me,HIR"����ϸ�ع۲����ͱڣ����ֿ�����Ծ��jump����ȥ��\n"NOR);
		return 1;
	 }
	}
	else
	{
		set("long", @LONG
��Ħ����������������Χɽ�ƶ��ͣ���ɽ���ţ�һ����������Ͽ����̶��
Ԩ��Ī�⡣�״��л�����̶�ɳ�����������̶��̶���Ħ�³ɱ��������漣��
�ʴ��پ������������������˿��쾮���Ĺ��̡��������ǳ��ɽ����������
ʯ�š�
LONG
);
		me->look(arg);
	}		
}

int do_jump(string arg)
{
	object room,me = this_player();
	object *player;
	int i;

	if(me->query_condition("killer")) return 0;//tjf������
   
	if (me->query(QUESTDIR3+"start")&&me->query_temp(QUESTDIR3+"askxiao") && !me->query_temp(QUESTDIR3+"lookcliff")&& !me->query(QUESTDIR3+"over")) {
		if( arg == "cliff" || arg == "�ͱ�" || arg == "����")
		{
			if(me->query_skill("dodge")<200) 
			{
				message_vision(HIC"\n$N����һ����������һԾ�ͱڣ�ȴͻȻ���ַ��ɽ�ߣ�ȴ�е��������ġ�\n"NOR,me);
				return 1;
			}
			message_vision(HIC"\n$N����һ������һ�������Ѿ������ͱڡ�\n"NOR, this_player());
			if (!(room = find_object(__DIR__"cliff")))
				room = load_object(__DIR__"cliff");
			if(!room)
			{ 
				tell_object(me,HIR"\n��������ô�������ֶ�����ԭ��!\n");
				log_file("quest/TLBB", sprintf("%s(%s)ȱ��cliff.c�ļ���\n", me->name(1),me->query("id")) );	
			}
			else
			{
				player = all_inventory(room);
				for (i = 0; i < sizeof(player); i++) {
					if (player[i]->is_character()) return notify_fail(YEL"��ͻȻ����������֮��������С���Ѿ���"+player[i]->query("name")+"�����棬������޷�վ�ȡ�\n��̾�˿�����ֻ�����һ���±ڣ�������������"NOR);
				}         	 
				tell_object(me,HIY"��û���뵽������ͱ��Ͼ�Ȼ������˴�Ŀռ������ţ������ǵ�����ԭ��������ĵص�֮һ��\n"NOR);
				me->move(room);
			}
			return 1;
		}
	}
	return 0;
}
int do_han(string arg)
{
	object me, env;
	int count;

  me = this_player();
  
  //�����ҽ�����Ӫ��������ʱ�����Ӫ
  
	if (localtime(TIME_TICK)[2] > 2 && !me->query(QUESTDIR4+"start"))  return 0;

	env = this_object();
	count = me->query_temp(QUESTDIR4+"count");
	if(!me->query(QUESTDIR3+"good") )return 0;
	if(!me->query(QUESTDIR4+"start")&&!me->query_temp(QUESTDIR4+"dagouzhen")) return 0;
	if(!me->query(QUESTDIR4+"start")&&!me->query_temp(QUESTDIR4+"shaolinzhen")) return 0;
	if(me->query_condition("killer")) return 0;//tjf������
	if (present("wu shi", env))
		return notify_fail(HIR"һƷ�úȵ����������ҹ�����һ�����С��ʲô����\n"NOR);
	if (me->is_busy())
		return notify_fail("��Ҫ��ʲô���ȴ������ɡ�\n");

	if ( count > 3 ){
    message_vision(HIC"$N���˿���������������"+me->name()+HIC"�����������������������ȥ��Զ��\n"NOR, me);
		me->start_busy(1);
		remove_call_out("happen");
		call_out("happen", 10, me);
		return 1;
	}
	else
	{
		if(random(2)) me->start_busy(1);
    me->add_temp(QUESTDIR4+"count",1);
    tell_object(me,HIY"�㳢�Ժ���һ���������ƺ����޷�Ӧ��\n"NOR);
	}
	return 1;
}

void happen(object me)
{
	object ob, env;

	env = this_object();
	if (!me) return;
	if(!me->query(QUESTDIR3+"good") )return 0;
	if (me->query_temp(QUESTDIR4+"count")<3) return;
	
	if (!(ob = present("dizi", env))) {
                ob = new("/d/gb/npc/dizi");
                ob->set("party","gb");
		ob->move(env);
		tell_room(env, HIY"ҹɫ�����˿�����һ����ֻ��һ��ؤ����Ӽ������˹�����\n"NOR, ({}));
	}
	if (!present(me, env)||(!me->query_temp(QUESTDIR4+"anhao")&&!me->query(QUESTDIR4+"start"))) {
		tell_room(env, CYN"ؤ���Ĵ����˿���������üת�����ˡ�\n"NOR, ({}));
		destruct(ob);
		return;
	}
  message_vision(HIW"ؤ�������$Nһ���֣������������ǵػ�����\n"NOR, me);
  me->start_busy(2);
}

int do_da(string arg)
{
	object me, ob,room,*obj;
	int i;
	me = this_player();
	if (!me) return 0;
  if (me->query_temp(QUESTDIR4+"count")<3) return 0;

	if (me->is_busy() || !arg )
		return notify_fail("��Ҫ˵ʲô���ȴ������ɡ�\n");

  if (!present("gaibang dizi", this_object())){
		message_vision(CYN"ؤ�������Զ����������"+me->name()+""CYN"���������ˣ���\n"NOR, me);
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
		me->start_busy(1);
		return 1;
	}
  ob = present("gaibang dizi", this_object());
  obj = deep_inventory(me);
  i = sizeof(obj);
  while (i--)
    if (obj[i]->is_character())
       me->set_temp("out",1);
  if (me->query_temp("out")){
		message_vision(HIY"$N������üͷ����"+me->name()+HIY"����������λ��......���������ˣ���\n"NOR,ob,me);
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
		me->delete_temp("out");
		me->start_busy(1);
		destruct(ob);
		return 1;
	}
	
    if (arg==me->query_temp(QUESTDIR4+"anhao")||me->query(QUESTDIR4+"start")) {
	  me->start_busy(1);
	  message_vision(HIC"$N��$n���˵�ͷ��\n"NOR, ob,me);
	  //ֻ��һ������
	  obj = users();
	  i = sizeof(obj);
	  while(i--) {
		  if ( obj[i]->query_temp(QUESTDIR4+"godaliao") && obj[i]!=me) 
		  {
			  message_vision(HIY"$N΢Ц�ŵ������õ����ˣ��Ѿ���"+obj[i]->query("name")+RANK_D->query_respect(obj[i]) +"ǰ������Ӫ��ȥ�ˣ�\n"NOR,ob,me);
			  message_vision(HIY"$N���˻�ͷ����"+obj[i]->query("name")+RANK_D->query_respect(obj[i]) +"�书��ǽ������ûʲô���⣡�����Ļ����������ˣ�\n"NOR,ob,me);
			  message_vision(HIY"$N�����ʼ磬���˸�Ҿ��ת���뿪�ˡ�\n"NOR,ob,me);
			  me->delete_temp("quest/�����˲�");
			  me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
			  log_file("quest/TLBB", sprintf("%s(%s)��ʼ������壬����%s(%s)��ͻʧ�ܡ����飺%d��\n", me->name(1),me->query("id"), obj[i]->name(1),obj[i]->query("id"), me->query("combat_exp")) ); 
			  destruct(ob);
			  return 1;
		  }
	  }
      
	  message_vision(HIC"$N˵������"+me->name()+"��������ͳ�����������������\n"NOR, ob,me);
	  if (!(room = find_object(__DIR__"daliao/shulin")))
		  room = load_object(__DIR__"daliao/shulin");
	  if(!room)
	  { 
		  tell_object(me,HIR"\n�㷢�����Ǿ�Ȼ����ԭ��!\n");
		  log_file("quest/TLBB", sprintf("%s(%s)ȱ���ļ�..daliao/shulin.c��\n", me->name(1),me->query("id")) ); 
	  	  return 1;
	  }

	  tell_object(me,HIY"�����ؤ����Ӽ�������ȥ����ͻȻ������ؤ������Ṧȷʵ����ؤ�ﲻ��Ϊ���µ�һ�\n"NOR);
	  message_vision(YEL"$N����ææ�뿪��Ħ�¡�\n"NOR,me);
	  message_vision(YEL"$N����ææ�뿪��Ħ�¡�\n"NOR,ob);
	  me->move(room);
	  ob->move(room);
	  message_vision(YEL"$N����ææ����"+room->query("short")+YEL"��\n"NOR,me);
	  message_vision(YEL"$N����ææ����"+room->query("short")+YEL"��\n"NOR,ob);
	  message_vision(HIC"\n$N��$n���˵�ͷ��\n"NOR, ob,me);
	  message_vision(CYN"$N˵������һֱ���о����ɱ���Ӫ�������и��ˣ����м���������ʿ��Ҫ��Ӧ��"+me->name()+CYN"����С�ģ���һ·���²���һ·��ɱ����\n"NOR, ob,me);
	  message_vision(CYN"$N˵������"+RANK_D->query_respect(me) +"�����ȥ�������ڣ����Ե��dianhuo����������ң�֮���Ż�Ӫ������������������˵����Ӫ���ø�������\n"NOR, ob,me);
	  message_vision(HIC"$N����$n���˻��֡�\n"NOR, ob,me);
	  message_vision(YEL"$N����ææ�뿪"+room->query("short")+YEL"��\n"NOR,ob);
	  log_file("quest/TLBB", sprintf("%s(%s)�Ѿ�������ɣ���ʼ������塣���飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) ); 
	  me->set_temp(QUESTDIR4+"godaliao",1);
	  me->set(QUESTDIR4+"start",1);
	  destruct(ob);
	  return 1;
	}
	message_vision(HIY"$Nץ�����������˰���˵������"+arg+"����\n"NOR, me);
	message_vision(HIY"$N������üͷ����"+me->query("name")+HIY"�������˼��......"+arg+"��\n"NOR,ob,me);
	message_vision(HIY"$N������üͷ��\n"NOR,ob);
	me->start_busy(1);
	return 1;
} 
 int valid_leave(object me, string dir)
 {
        object ob;
        if (base_name(this_object())==__DIR__"silk8" && dir == "south" && (is_wanted(me) || !userp(me)))
                return 0;
 
        if(me->query_temp("wait_target") && objectp(present("anran zi", environment(me))))
                return notify_fail("��Ȼ��������������ǰ���ȵ�������������ҹ�������\n");
 
        if(me->query_temp("xx_rob") 
        && objectp(ob = present("hubiao biaoshi", environment(me)))
        && ob->query("target") == me)
                return notify_fail("������ʦ������ס���ȥ·�����������������ˣ�\n");  
 
        if(me->query_temp("xx_rob") && objectp(present("shangdui", environment(me))))
                return notify_fail("�̶��������أ�����(qiang)����\n");  
 
        return ::valid_leave(me, dir);
 }
