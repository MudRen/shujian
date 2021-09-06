//caiji@SJ 8/24/2000

inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  	int north=(POS/10+4)%5*10+POS%10,south=(POS/10+1)%5*10+POS%10,
      	east=POS/10*10+(POS%10+1)%5,west=POS/10*10+(POS%10+4)%5;
  	set ("short", "�����");
  	set ("long", @LONG
һƬƽ̹�ȵأ������Ǵ�ɽ���ơ������������ģ�����ʮ�ֲֿ�������
�������𣬸��ֶ���������������¶��ǳ��긯�ݰ�Ҷ�óɵ����ࡣ����
��ɽ��ͨ���йν����������㼡���������ۡ�
LONG);

  	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"duchonggu"+north,
		"south" : __DIR__"duchonggu"+south,
		"east" : __DIR__"duchonggu"+east,
		"west" : __DIR__"duchonggu"+west,
	]));
	set("outdoors","���޺�");

	if(POS%5==0) set("exits/southeast", __DIR__"duchonggu-out");

	if(POS%3)
	set("objects",([
		FOOD_D("hulu") : 2,
		FOOD_D("xzhang") : 1,
	]));

	setup();

  	setup();
}

void init() 
{
        mapping fam=this_player()->query("family");
        add_action("do_action", ({"exert"}));

	if (present("du chong")) return;
	if( this_player()->query_temp("xx_job4")
	 && mapp(fam)
	 && fam["family_name"] =="������"
	 && this_player()->query_condition("job_busy")){
		add_action("do_burn", "burn");
		add_action("do_catch", "dai");
		remove_call_out("greeting");
		if(!random(4)){
			call_out("greeting",1,this_player(),this_object());
			this_player()->start_busy(2+random(2));
		}
	}
}

void greeting(object me,object env)
{
	object staff;
	if (!me || environment(me)!=env) return;
	tell_object(me,BLU"�����òݴ���ɪɪ���죬�̲���һ��ζ����㲻��ͣ���������뿴��������\n"NOR);
	me->set_temp("xx_burned",1);
	if(POS==(random(5)*10+random(5)) && (string)me->query("family/family_name")=="������" &&
	(int)me->query_skill("huagong-dafa", 1) > 100){
		staff=unew(BINGQI_D("sword/qm-jian"));
		if(staff) {
			destruct(staff);
			staff=unew(BINGQI_D("staff/gangzhang-sp"));
		}
		if(staff){ 
			staff->move(environment(me));
			message_vision("�ڲݴ��У�$N��������һ����ֵ������ϸһ����ԭ����һ����ͨ�ĸ��ȡ�\n",me);
		}
		return;
	}
}

int do_burn(string arg)
{
	int costj;
	object me;
	me = this_player();
	if( arg != "liuhuang" && arg!="liu huang")return notify_fail("�����ȼʲô�������ӣ�\n");
	if (me->is_busy()) return notify_fail("��������æ���أ�û�����������ն��������ӣ�\n");
	if (me->is_fighting()) return notify_fail("������ս���У��޷��ڳ����������ӣ�\n");
	if (!present("fire", me)) return notify_fail("��û�л��ۣ��������\n");
	if (!present("liu huang", me)) return notify_fail("��û������֮��������\n");

	costj = random((int)me->query("int")/2)+2;

	me->add("jingli", -costj);
  
	message_vision("$N�����������һС�飬���ڵ��ϣ��û��۵�ȼ������������\n",me);
	me->start_busy(1+random(2));
	if(!random(2))call_out("greeting",1,this_player(),this_object());
	else message_vision("����ĳ����ƺ��Ѿ���������ץ���ˣ���ֻ��ȥ�����ط���һ���ˡ�\n",me);
	return 1;
}

int do_catch(string arg)
{
	int costj;
	object me;
	me = this_player();
	if(!me->query_temp("xx_burned")) return notify_fail("�㻹û�аѳ�����������\n");
	if( arg != "chongzi" && arg!="chong zi")return notify_fail("�����ʲô����\n");
	if (me->is_busy()) return notify_fail("��������æ���أ�û����������ץ���ӣ�\n");
	if (me->is_fighting()) return notify_fail("������ս���У��޷��ڳ�����ץ���ӣ�\n");
	if (!me->query_condition("xx_catch")) return notify_fail("�����ڲ���ץ���ӣ���������û����������ɣ�\n");

	costj = random((int)me->query("int")/2)+2;

	me->add("jingli", -costj);

	message_vision("$N��ǰһ�ˣ����һ���ӽ���ֻ���ӡ�\n",me);
	me->start_busy(1+random(3));
	if(!random(3)) call_out("greeting1",2,me,this_object());
	else message_vision("���ӱ�$Nһ�ţ�����ݴԲ����ˡ�\n",me);
	return 1;
}

void greeting1(object me,object env)
{
	object chongzi;

	if (!me || !env || environment(me)!=env) return;
	chongzi=new(__DIR__"obj/duchong");
	chongzi->move(env);
	chongzi->set("target",me);
	chongzi->do_copy(me);
	tell_object(me,MAG"�����ǰһ����ԭ����һֻ"+chongzi->name()+MAG+"ȫ�����⣬ͷ��͹����Ѱ��������ͬ��\n\n"NOR);
}

int valid_leave(object me, string dir)
{
	me->delete_temp("xx_burned");
	return ::valid_leave(me, dir);
}

int do_action(string arg)
{
	if(!arg){
		write("���������������\n");
		return 1;
	}
	if(arg == "roar"){
		write("������ô�ž�����Ϲ����ʲô��\n");
		return 1;
	}
}
