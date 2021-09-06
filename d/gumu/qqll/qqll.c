// qqll.c ��������
// kxkxkx 2004��3��
//�����ˡ����(Ciwei)����ʽ��/d/gumu/qqll/qqll.c �� 410 ��

// �����������������ԣ��ֱ��ڳ���ͬ�ĵط����ã�
//    "pal"            <--   team member object
//    "ok"             <--   ����ok
//    "killer"         <--   ��ǰ��killer object
//    "killers"        <--   �ѳ��ֵ�����ɱ����
//    "max_killers"    <--   �����ֵ�����ɱ����
//    "d_area_n"       <--   Ŀ�ĵ�������
//    "d_room"         <--   Ŀ�ĵ�object

#include <ansi.h>
#include <command.h>

inherit ITEM;

private nomask int check_team_hook(string arg);
private nomask int qqll_valid_team();
private nomask void check_team_hook_completion(object user);

private nomask int ask_hook(string arg);
private nomask mixed do_ask(string arg);

private nomask int go_hook(string arg);
private nomask int move_with_killer();
//private nomask 
int encounter_killer();
private nomask int encounter_cyl();

void give_hook_completion(object user);

void create()
{
	set_name(HIG"����ʯ"NOR, ({"qiyan shi","qiyan stone"}));
	set_weight(25000);
	if(clonep())
	set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������֮������ʯ��\n"
		"����֪��Ϊ�α��˳�Ϊ���������硱��\n"
		"����ӿ��������߸�Сʯ�ۡ�\n"
		"��Լ���ɱ������ǵ���״��\n"
		"����һ����ͨ�ò�������ͨ��ʯͷ��\n"
		"���Ӻ�������ɽ����Ӧ�ö���ǣ�\n"
		"����֪��Ϊ�α��˳�Ϊ[��������]��\n"
		);
		set("value", 800000);
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_steal", 1);
		set("no_give",1);
	}
	setup();   
}

void init()
{
	add_action("check_team_hook", "", 1);
	add_action("ask_hook", "ask ", 2);
	add_action("go_hook", "go ", 2);	
	
	call_out("dest", random(200)+1200);	
}

void debug(string msg)
{
	return;
	message("wizard:ciwei",msg+"\n",users() );
}

void debug_start()
{
	object ob;
	
	ob = new(__DIR__"cyl");
	ob->move(environment(this_player()));
	set("cyl",ob);
	ob = find_player("shadao@ln");
	set("pal",ob);	
}

int can_cmds()
{
	object pal = query("pal",1);
	object user = this_player();
	
	if(wizardp(user) && user->query("env/test")) return 1;
		
	if(!pal) return 0;
	if(!user) return 0;
	if(!environment(user)) return 0;
		
	if(!present(pal,environment(user)))
	{
		tell_object(user,HIY"��Ĵȥ�����ˣ�\n"NOR);
		return 0;
	}
	return 1;
}

void dest()
{
	message_vision("$N��Ȼ������·�ϣ�����Ҳ�����ˡ�\n", this_object());
	destruct(this_object());
}

// ���team�Ƿ����Ҫ�����Ƿ���0����command�ܱ�����������
private nomask int check_team_hook(string arg)
{
	object user;
	
	user = this_user();
	if(qqll_valid_team() || (wizardp(user) && user->query("env/test")) )
	return 0;
	// team����Ҫ���ˣ�����ʧ��
	call_out("check_team_hook_completion", 1, user);
	return 0;
}

// �жϣ��õ������ģ�team�Ƿ���Ч
private nomask int qqll_valid_team()
{
	object user, *team;
	
	user = this_user();
	team = user->query_team();
	
	debug( sprintf("Me:%O \nPal:%O\n T:%O \n",user,query("pal", 1),team) );
	
	if(user->is_team_leader() &&
	sizeof(team) == 2 &&
	team[1] == query("pal", 1)) {
		return 1;
	}
	
	debug("error\n");	
	return 0;
}

// check_team_hook��compeltion����
// ע�⣺������Ϊteam�����ʧ�ܣ������Ϊteam�ĳ�Աquit��dismissʱ��
// �Ǹ���Ա��job_busy������٣��������load�Ǹ���Ա���а�ȫ����
private nomask void check_team_hook_completion(object user)
{
	object pal, killer;
	
	if(!user->is_ghost())
	user->apply_condition("job_busy", 10); // ���û��
	pal = query("pal", 1);
	// ���ͬ��quit�ˣ����޷���������job_busy�ˡ�
	if(pal && !pal->is_ghost()) {
		pal->apply_condition("job_busy", 10);  // ���ûquit��û��
	}
	killer = query("killer", 1);
	if(!killer) {
		tell_room(environment(user), query("name") + "ͻȻ��" +
		user->query("name") + "�����ϵ����������ˣ�\n", ({user}));
		tell_object(user, query("name") +
		"ͻȻ��������ϵ����������ˣ�\n");
	}
	else {
		if(user->is_ghost()) {
			killer->force_me("yeah");
			tell_room(environment(killer), killer->query("name") + "��" +
			user->query("name") + "��ʬ�����ѳ�һ" + query("unit") +
			query("name") + "��ת��������Ͳ����ˡ�\n");
		}
		else {
			killer->force_me("say �ߣ�����������ˡ�\n");
			tell_room(environment(killer), killer->query("name") +
			"����ææ���뿪�ˡ�\n");
		}
		destruct(killer);
	}
	destruct(this_object());
}


int check(object ob,string place)
{
	if(!objectp(ob)
	|| !environment(ob)
	|| environment(ob)->query("no_fight")
	|| environment(ob)->query("quest")
	|| strsrch(base_name(environment(ob)),place) != 0 ) return 0;
	return 1;
}
// �ڳ�ʼ��������npc����������������
private nomask int ask_hook(string arg)
{
	object user, npc , target;
	string str;
	object* living;
	int i,j;   	 
	
	if(!(npc = do_ask(arg)))
	return 0;   // ����������
	
	user = this_user();
	message_vision("$N��$n�����йء�" + HIG +"������" + NOR + "������Ϣ��\n", user, npc);
	npc->force_me("say Ŷ���ϴ�ȷʵ����ôһ����������");
	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living) -1) continue;
		if(check(living[j],query("target_place")) ){
			target = living[j];
			str = environment(target)->query("short");
			if( str == "��ɮ��" 
			|| str == HIR"������"NOR
			|| str == "��շ�ħȦ" ) continue;
		}
	}
	
	if(!target)
	{
		npc->force_me("whisper "+user->query("id")+" ������û�������ȥ�����ˡ�");
		return 1;
	}
	
	set("real_place",base_name(environment(target)));
	
	// ������whisper���������˵��΢��ȫЩ
	npc->force_me("whisper " + user->query("id") +
	" �����������Ѿ�ȥ" + str + "�ˡ�");   
	set("start", 1);  // �Ӵ��Ժ󣬿�ʼ������ɱ��/����������
	return 1;
}

// �ж��Ƿ��ܹ���npc���������������䣬
// ��������򷵻�npc object�����򷵻�0
private nomask mixed do_ask(string arg)
{
	object user, room, obj;
	string askee, topic;
	
	user = this_user();
	room = environment(user);
	//room_f = base_name(room);
	
	//if(!present(query("pal"),room)) //Partner���ڱ���
	//return 0;	
	if(!can_cmds()) return 0;
	
	if(user->is_busy())
	return 0;   // team leaderæ
	if(sscanf(arg, "%s about %s", askee, topic) != 2)
	return 0;   // ask�����
	if(topic != "������")
	return 0;   // �ʵĲ��Ǵ�����
	
	obj = present(askee, room);
	if(!objectp(obj))
	return 0;   // û�����
	if(!living(obj))
	return 0;   // ���ǻ���
	if(!obj->query("can_speak"))
	return 0;   // ����˵��
	if(obj->query("mute"))
	return 0;   // �ư�
	if(!userp(obj))
	return 0;   // �����
	if(!living(obj))
	return 0;
	if(random(2) < 1)
	return 0;   // 1/2�ĸ��ʲ�֪��
	if(obj->query("id") != query("target_player"))
	return 0;
	
	return obj;
}

// ��������������󣬴���team leader���ƶ����ܳ��ֵ�
// ���������ɱ�֣���������
// ע�⣬ֻ��team leader�����ƶ��Ż���ܳ�����Щ�����
// ��Ϊfollow���˶��ƶ����򲻻�������������
// ÿ�����ֻ����һ������ɱ�֣���ϵͳforce��follow
// team leader����ʹfollow��nofight roomҲ������follow
// ���������Ȼ�п��ܰ�����ɱ�ִ���ȥɱ����ɱ��һ������
// ɱ�ֺ󣬲Ż�����һ�����֣�ɱ������3-5������ɱ�ֺ�
// �ߵ�ָ��λ�òŻ��д��������֣�������ֻ����2���ӣ���
// ��û�м�ʱgive chunyu lan linglong, ����ʵ���Ͼ�ʧ���ˡ�
private nomask int go_hook(string arg)
{
	object user, *team;
	user = this_user();
	team = user->query_team();
	if(!GO_CMD->main(user, arg))
	return 0;   // �������û�г�·
	if(query("iamover")) return 1;//Cyl�Ѿ�����
	if(!query("start"))
	return 1;   // ��û��ʼ��������ɱ��
	add("steps", 1);  // �����ƶ��Ĳ���
	if(move_with_killer())
	return 1;   // ������ɱ��ս�����ƶ�
	if(!present(query("pal"), environment(user))) return 1;
	if(encounter_killer())
	return 1;   // �����µ�����ɱ��
	if(encounter_cyl())
	return 1;   // ����������
	return 1;
}
// �ж��Ƿ��ں�����ɱ��ս�����ƶ�
private nomask int move_with_killer()
{
	object killer;
	killer = this_object()->query("killer", 1);
	if(!killer)
	return 0;
	this_user()->start_busy(2);
	return 1;
}

// ����������ɱ�֣�
//private nomask 
int encounter_killer()
{
	object user, room, killer,pal;
	
	pal = query("pal", 1);	
	if(!pal) return 0;
	if(!can_cmds()) return 0;
	
	if(query("killers") == query("max_killers"))
	return 0;   // û�и��������ɱ��	
	if(query("steps") < 10)
	return 0;   // ��û���ߵ�10�� 
	if(random(4) < 3)
	return 0;   // 3/4�ĸ���û����ɱ��	
	user = this_user();
	room = environment(user);
	if(room->query("no_fight"))
	return 0;   // �ڷ�ս������	
	set("steps", 0);  // ���貽��	
	killer = new(__DIR__"killer");
	killer->set("target", this_object());
	set("killer", killer);
	tell_object(user,
	YEL"����������е���ʯԽ��Խ��������ٲ�ά�衭����\n"NOR);
	tell_room(room, RED"һ������ɱ�ִ�·�����˳����������ȵ���"
	"�����������ı������£���Ȼȡ�����������\n"NOR);
	
	killer->setparty(1+random(10),pal->query("max_pot")-80,pal->query("combat_exp")*12/10 );
		
	killer->add_temp("apply/damage",- pal->query("max_pot") / 5 );
	killer->add_temp("apply/attack",-  pal->query("max_pot") / 5 );
			
	killer->do_kill(user);
	killer->move(room);
	killer->force_me("follow " + user->query("id"));      
	killer->kill_ob(user);
	
	killer->no_die_ppl(user,this_object());
	
	user->start_busy(2);   
	return 1;
}

// ������������
private nomask int encounter_cyl()
{
	object room, cyl;
	
	room = environment(this_user());
	
	if(!can_cmds()) return 0;
	
	if(query("killer")) return 0;
	
	if(query("killers") < query("max_killers"))
	return 0;   // ��������ɱ�ֳ���	
	if(query("real_place") != base_name(room))
	return 0;	
	set("start", 0);  // �����һ����ң��ظ����ֶ��������
	set("iamover",1);
	cyl = new(__DIR__"cyl");
	set("cyl", cyl);
	tell_room(room, cyl->query("name") + "�������˹�����\n");
	cyl->move(room);
	return 1;
}

void give_hook_completion(object user)
{
	object cyl, room;

	cyl = query("cyl", 1);
	room = environment(user);
	message_vision("$N΢΢һЦ��̾������������Ҳ�ǳ��ˣ���Ȼ���������˵����⡣��\n",cyl);   
	cyl->force_me("say " HIY"��ʯһ�����������磬�������ϣ�"
	"�������š���������Ҫָ����ӣ�\n"
	"̰���������飬������ʯ�����Ƶ�����Ϊ����֤���硣"
	"��ɽ����Ը�֪��ţ���Ӱɡ�"NOR);
	message_vision("$n��$Nһ"+query("unit")+query("name") + "��\n",user,cyl);
	message_vision("$Nһգ�ۣ��ֲ�֪������ȥ�ˡ�\n",cyl);
	destruct(cyl);
}