// /d/xingxiu/npc/ding.c 
// ding.c ������
// Update by caiji@SJ 8/8/2000

#include <ansi.h>
#include <get_place.h>

inherit NPC;
inherit F_MASTER;

#define TIME_TICK (time()*60)

string *drugs = ({"/obj/yao","/obj/yao1","/obj/yao","/obj/yao2","/obj/yao","/obj/yao3","/obj/yao",});
int give_reward(object me);
int give_drug();
string ask_job5();
string ask_job4();
string ask_job5_times();
string ask_fail();
int check(object ob);
string ask_job3();
string ask_job();
string ask_times();
string ask_san();
string ask_gou();
string ask_pay();

void create()
{
	set_name("������", ({ "ding chunqiu", "ding" }));
	set("nickname", "�����Ϲ�");
	set("long",
	"�����ɿ�ɽ��ʦ������ԭ������ʿ���ʹ���������Ϲֶ����\n"
	"����ɫ������ͷ���ˣ���������ף�ͯ�պ׷���\n"
	"�������ͼ���е���������һ�㡣\n");
	set("gender", "����");
	set("age", 60);
	set("per", 24);
	set("attitude", "friendly");
	set("no_bark",1);
	set("shen_type", -1);
	set("str", 30);
	set("int", 27);
	set("con", 28);
	set("dex", 32);
	set("max_qi", 6000);
	set("max_jing", 5000);
	set("eff_jingli", 3500);
	set("max_neili", 11000);
	set("jiali", 120);
	set("combat_exp", 2700000);
	set("unique", 1);
	set("shen", -200000);

	set_skill("force", 260);
	set_skill("huagong-dafa", 255);
	set_skill("dodge", 260);
	set_skill("zhaixingshu", 260);
	set_skill("strike", 260);
	set_skill("chousui-zhang", 260);
	set_skill("parry", 260);
	set_skill("claw", 260);
	set_skill("sanyin-zhua", 260);
	set_skill("staff", 260);
	set_skill("tianshan-zhang", 260);
	set_skill("literate", 130);
        set_skill("poison", 260);
        set_skill("hook", 260);
        set_skill("zhuihun-gou", 260);
	map_skill("force", "huagong-dafa");
		map_skill("hook", "zhuihun-gou");
	map_skill("dodge", "zhaixingshu");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");
	create_family("������", 1, "��ɽ��ʦ");
	set("inquiry", ([
	       "������" : "���������������ɿ�ɽ��ʦ, �����Ͽ��ͷ��",
	       "���޺�" : "��Ϲ������, ������ǡ�",
		 "����" : "�����Բ�����ﶼ�����ɵ���������",
	       "������" : "û��ûС�ġ��ٽ��ҷ����㡣",
		 "����" : "���������ɱ������������ʥ����ô������",
	     "��������" : "�Ժ�����ɡ�",
		 "����" : "���������ᡣ",
		 "��ҩ" : (: give_drug :),
		 "����" : (: ask_job :),
	       "��Цɢ" : (: ask_san :),
	   "��Ц��ңɢ" : (: ask_san :),
		"pantu" : (: ask_job5 :),
	       "�����" : (: ask_job4 :),
	    "duchonggu" : (: ask_job4 :),
		  "��ͽ": (: ask_job5 :),
		  "����": (: ask_fail :),
		  "fail": (: ask_fail :),
	  "ɱ��ͽ�Ĵ���": (: ask_job5_times :),
	    "ɱ��ͽ����": (: ask_job5_times :),
	    "job5_times": (: ask_job5_times :),
	     "��ľ����" : "���͵���ͷ����㡣",
		 "ľ��" : "ץ���������õġ�",
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
		(: perform_action, "strike.huoqiu" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
	}));

	set("drug_count",15);
	set("class", "taoist");

	set_temp("apply/damage", 20);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 60);
	setup();

	if (clonep()) {
		UPDATE_D->get_cloth(this_object());
		add_money("gold", 2);
	}
}
/*
int prevent_learn(object me,object weapon)
{
	mapping myfam;
	object ob;
	int shen;
	
	myfam = (mapping)ob->query("family");
	if(!myfam || (myfam["family_name"] != "������")) return 1;
	if(!ob->is_apprentice_of(this_object())) return 1;
	shen = ob->query("shen");
	if(shen > -1000 && shen < 0)
	{
		command("say ����ô��ģ�������һ��İ׵���Ϣ��");
		return 1;
	}
	else if(shen >= 0 && shen < 100000)
	{
		command("say ���ۣ���ҺͰ׵����˽��ͣ���������ǲ��ǣ�");
		return 1;
	}
	else if(shen >= 100000){
		command("say �㾹�ҺͰ׵����˽��ͣ������������ȥ�ɣ�");
		command("expell " + ob->query("id"));
		return 1;
	}
	return 0;
}
*/
void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();

	if(ob->query("job_time/���ް�ҩ"))
	{
		ob->add("job_time/���ް���",ob->query("job_time/���ް�ҩ"));
		ob->delete("job_time/���ް�ҩ");
	}
		
	if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_flatter", "flatter");
	add_action("do_xian", "xian");
	add_action("do_begsan", "begsan");
}

string ask_san()
{

	if((int)this_player()->query("combat_exp") < 200000
	 || (string)this_player()->query("family/family_name") != "������")
		  return "��ƾ��Ҳ��Ҫ��Цɢ��\n";

	if( query("started") != 1 ){
	   set("started", 1);
	   call_out("generate_sxs", 7200);//2 hours
	}

	if((int)this_player()->query_skill("poison", 1) < 200)
		  return "��Ķ����������ߣ��Ҳ����İ���Цɢ�����㡣";

	if((int)this_player()->query_skill("huagong-dafa", 1) < 240)
		  return "��Ļ����󷨻������ߣ��Ҳ����İ���Цɢ�����㡣";

	message_vision("�������$NЦ��������begsan����Ե����Ρ�\n", this_player());
	return "���԰�";
}

void generate_sxs()
{
	remove_call_out("generate_sxs");
	set("available", 1);
}

int do_begsan(string arg)
{
	object me, book;
	me = this_player();

	if( query("available") == 1 && clonep(book = unew(MEDICINE_D("sxs")))){
	  set("available", 0);
	  book -> move(me);
	  message_vision("$N����������Ե����һ����Цɢ���͸����ˡ�\n", me);
	  command("chat "+ me->query("name")+"��Ե���õ��ҵı����Ц��ңɢ����");
	  remove_call_out("generate_sxs");
	  call_out("generate_sxs", 7200);//2 hours
	  return 1;
	}
	return notify_fail("������˵���������Ĳ���ʱ��\n");
}

void greeting(object me)
{
	mapping myfam;
	int shen;

	if(!me || environment(me) != environment(this_object())) return;

	shen = me->query("shen");
        if ( file_name(environment(this_object())) != this_object()->query("startroom")) return;

	if(!myfam = (mapping)me->query("family"))
		command("say ��ǧ����������ɽ, Ī����������������ɣ�");
	else if(myfam["family_name"] != "������" ){
		if(!me->query_temp("xx_job"))
			command("say ��ǧ������������ɽ������Ľ�������ҵ��ʵ°ɣ�");
		else    command("nod " + me->query("id"));
	}

	else if(shen > -1000 && shen < 0)
		command("say ����ô��ģ�������һ��İ׵���Ϣ��");
	else if(shen >= 0 )//&& shen < 100000
		command("say ���ۣ���ҺͰ׵����˽��ͣ���������ǲ��ǣ�");
	/*else if(shen > 100000){
		command("say �㾹�ҺͰ׵����˽��ͣ������������ȥ�ɣ�");
		command("expell " + me->query("id"));
	}*/   // I move this to prevent_learn By Ciwei@SJ
	else command("say ��ͽ��������������ô���ˣ�");
	if(me->query("xx_job5_finished"))call_out("give_reward",1,me);
}

void attempt_apprentice(object me)
{
	if(me->query("family/family_name") != "������"
	 && me->query("expell/family_name") != "������"){
		say("���ɶ�"+me->name()+"������\n");
		return;
	}
	if ((int)me->query("shen") > -50000) {
		command("say ����Խ����Խ��׵������Ե׵ġ�");
		return;
	}
/*        if (me->query("job_time/����")+me->query("job_time/������ͽ")+me->query("job_time/���ް���") < 500) {
		command("say ��Ӧ�ö��Ϊ�����ҷֵ��ֵ��ǳ���ǡ�");
		return;
}

*/
	if(me->query_skill("huagong-dafa",1) < 180){
		command("say ������Ļ����󷨻���������������ȥ����ͽ��ѧѧ�ɡ�");
		return;
	}
	if( me->query_temp("pending/flatter") ) {
		command("say ����˲������ɷ�����������������㣿");
		return;
	}
	else {
		command("say ���������ɱ������������ʥ����ô������");
		message_vision("�����Ϲ�΢��˫�ۣ������룬һ����$N����(flatter)�����ӡ�\n", me);
		me->set_temp("pending/flatter", 1);
	}

}

int do_flatter(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();

	if( !arg ) return notify_fail("��Ҫ�������ɵ�ʲô�Ṧΰ����\n");
	if(me->query_condition("gb_mission") || me->query_condition("gb_busy"))
		return notify_fail("������������л��ӣ����ӵ����ؤ�������˵��\n");
	if(this_player()->query("jing") < 10)
		return notify_fail("��̫���ˣ��ȵ����İɣ�\n");

	switch(random(5)) {
		case 0 : message_vision("\n$N��$n�����޵��������˼�һ����������ѣ�һҡ�������޹⣡\n", me,ob); break;
		case 1 : message_vision("\n$N��$n�����޵����������ɴ���ڶ����������ԣ����������ţ������һ������������֮�أ�\n", me,ob); break;
		case 2 : message_vision("\n$N��$n�����޵�����������������һϯ��������Ī����ֻ����������֣�С�˸��������������ǣ�\n", me,ob); break;
		case 3 : message_vision("\n$N��$n�����޵�������������֮�������������֮�����̹��Ͽ���ٵ����������޵ڶ����������ɵ����£�\n", me,ob); break;
		case 4 : message_vision("\n$N��$n�����޵��������񹦸��������µ�һ��ս�޲�ʤ�����޲��ˣ�\n", me,ob); break;
	}

	message_vision(HIY"$N����������" + arg + "\n"NOR, this_player());
	this_player()->set("jing", 1);
	if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
	 && strsrch(arg, "�������") >=0 && strsrch(arg, "�Ž��ޱ�") >=0 )) {
		command("smile");
		command("say �⻹��ࡣ\n");
		if(this_player()->query_temp("pending/flatter")){
			this_player()->delete_temp("pending/flatter");
			command("recruit " + this_player()->query("id"));
			this_player()->set("title",HIB "�����Ϲ���ǰ��ͽ" NOR);
			CHANNEL_D->do_channel(this_player(), "chat",  "�������ɣ�������أ��������Ž��ޱȣ�");
			return 1;
		}
		else{
			command("say �����������ô���������ǰ;������������\n");
			this_player()->set_temp("ding_flatter", 1);
			return 1;
		}
	}
	else command("say û������");
	return 1;
}

int give_drug()
{
	object drug, me, ob;

	me = this_object();
	ob = this_player();

	if(ob->query("family/family_name") == "������" && (ob->query_skill("huagong-dafa", 1) > 79)){
		if(me->query("drug_count") >= 1 && !ob->query_temp("drug_give")){
			add("drug_count", -1);
			drug = new("/d/xingxiu" + drugs[random(sizeof(drugs))] );
			drug->move(ob);
			ob->set_temp("drug_give", 1);
			message_vision("$N��$n���˵�ͷ������$nһС��ҩ�ۡ�\n", me, ob);
			return 1;
		}
		if(ob->query_temp("drug_give"))
			command("say �Ҳ��Ǹ���������");
		else command("say ����������������ʦ���������ˡ�");
		return 1;
	}
	else return 0;
}

string ask_job()
{
	object me, ob;
	me = this_player();

	if (me->query("family/family_name") == "�䵱��"
	 || me->query("family/family_name") == "������"
	 || me->query("family/family_name") == "��ü��"
	 || me->query("family/family_name") == "��ɽ��"
	 || me->query("family/family_name") == "������")
		return "���ǰ׵����Ե׵İɣ���������ҹ���ȥ������";
	if (me->query("combat_exp") < 1000000)
		return "�����������ټӰ����������ܿ�Ϳ���Ϊ�����ҷ����ˡ�";
	if (me->query("job_name") == "���ɷ���")
		return "�����������黹�ã���������Ϊ�ҷ��ǡ�";
	if (me->query("combat_exp") > 4000000)
		return "�����������ʲô��û��Ȥ����������Ϊ�ҷ��ǡ�";
	if (me->query("shen") >= 0 || me->query("shen") > -(me->query("combat_exp")/10))
		return "ͽ������������ĳ��������ڰ�����Щ���㲻��Ҳ�ա�";
	if (interactive(me) && me->query_temp("job_busy"))
		return "��˵Ҫ�����ɷ��ǣ���ô�������﷢����";
	if (interactive(me) && me->query_condition("wait_xx_task"))
		return "�����������黹�ã���������Ϊ�ҷ��ǡ�";
	if (me->query_condition("job_busy"))
		return "�����������黹�ã���������Ϊ�ҷ��ǡ�";

	ob = new("/d/xingxiu/obj/di");
	ob->move(me);
	ob->set("name", BLU"����̵�"NOR);
	ob->set("long", BLU"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���������Ө�ɰ���\n" NOR);
	ob->set("xx_user", getuid(me));
	me->set_temp("xx_job", 1);
	message_vision("$N�ó�һֻ���ƶ̵ѣ�����$n��\n", this_object(), me);
	return "������������鲻�ѣ�ͽ����Ҫ���Ϊ�ҷ��ǲ��ǣ�\n";
}

void destroying(object obj, object me)
{
	message_vision("$N����$n��ϸ�ض�����һ���������ص��˵�ͷ������¶����Ц�ݡ�\n", me, obj);
	destruct(obj);
}

void dest(object ob)
{
	if (!ob) return;
	if (userp(ob)) command("drop "+ob->parse_command_id_list()[0]);
	else destruct(ob);
}

int do_xian(string arg)
{
	object who, me, ob;
	mapping quest;
	who = this_player();
	me = this_object();

	if(who->is_busy() || who->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(me->is_busy() || me->is_fighting())
		return notify_fail("û����������æ����\n");
	if(!arg || !objectp(ob = present(arg, who)))
		return notify_fail("��Ҫ�׸�����ʲô������\n");
	if(!who->query_temp("xx_job"))
		return notify_fail("���������ڵ����黹û����������׶�����\n");

	message_vision(HIY"\n$n�Ϲ��Ͼ��ؽ�"+ob->query("name")+HIY"�ó���˫�����ϣ���Ҫ�׸�$N��\n\n"NOR, me, who);

	if(me->is_busy()) {
		command("say ����æ���أ���ȵȡ�");
		return notify_fail("��������ȵȡ�\n");
	}
	if(!mapp(quest = who->query_temp("quest")) || !quest["id"]){
		command("say ���ø�"+ob->name()+CYN"���Ҹ��"NOR);
		return notify_fail("���ɶ��ⶫ��������Ȥ��\n");
	}
	if ( quest["time"] < TIME_TICK){
		command("say �ţ���ô�òŰ��꣬���ʲôȥ�ˣ����ҹ�һ��ȥ��");
		who->apply_condition("wait_xx_task", 40);
		return notify_fail("���ˣ����������ˡ�\n");
	}
	if(userp(ob)){
		command("stare " + who->query("id"));
		command("say �����üٻ�����ƭ�����ɣ����ҹ���ȥ��");
		message_vision("\n˵��$N����һ�ӣ�һ���ھ��������ͽ�$nɨ�����⣡\n\n", me, who);
		who->move("/d/xingxiu/ryd1");
		message("vision","ֻ����������һ����������"+who->query("name")+"�����¶���ֱ���˳�����ˤ�˸��Ľų��죡\n", environment(who), who);
		who->receive_wound("jing", 200);
		who->receive_wound("qi", 250);
		who->receive_damage("neili", 600);
		who->receive_damage("jingli", 500);
		who->apply_condition("wait_xx_task", 30);
		who->delete_temp("quest");
		who->set_temp("last_id", quest["last_id"]);
		who->start_busy(5);
		return notify_fail("��⣬�����ˣ�\n");
	}
	if(ob->query("name") != quest["name"] || ob->query("id") != quest["id"]) {
		command("hmm " + who->query("id"));
		command("say ���ø�"+ob->query("name")+"����������ʲô�ã�");
		return notify_fail("���������״����ˡ�\n");
	}

	ob->move(me);
	me->start_busy(random(2));
	who->start_busy(2);
	destroying(ob, me);
	call_out("done", 3, who);
	return 1;
}

void done(object me)
{
	if(!me || environment(me) != environment(this_object())) return;

	command("pat " + me->query("id"));
	command("say ��������Ȼ���ҵ�����������Ҫ�Ķ������Ҿ�ָ��ָ����ɡ�");
	if(me->query("family/family_name") == "������") {
		if(me->query_skill("huagong-dafa",1) < 180)
			me->improve_skill("huagong-dafa", me->query("job_time/����"));
		if(me->query_skill("poison",1) < 180)
			me->improve_skill("poison", me->query("job_time/����"));		
		tell_object(me, "��Ŀǰ�Ѿ�Ϊ���ɷֵ���"+chinese_number(me->query("job_time/����"))+"���ǳ\n");
	}
	tell_object(me, "���������ɵ�ָ�㣬��������˲��٣�\n");
	
	TASK_D->give_reward(me, me->query_temp("quest"), -1, ABS(me->query("job_time/����")/25),this_object(),"����");
	//GIFT_D->check_count(me,this_object(),"����");
	//me->add("job_time/����", 1);
			
	log_file("job/fenyou",sprintf("%-18s ������JOB���þ��� %d��Ǳ�� %d��\n",
		me->query("name")+"("+getuid(me)+")",
		me->query_temp("quest/exp_reward"), me->query_temp("quest/pot_reward")),me);
        me->set("job_name","���ɷ���");
	me->clear_condition("job_busy");
}

string *exclude_place = ({
	"/d/wuguan/","/d/death/","/d/wizard/","/d/sld/",
});

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("race") !="����"
	 || userp(ob)
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("quest")
         || room->query("outdoors") == "���ش��"
	 || member_array(file_name(room), exclude_place) != -1
	 || strsrch(room_name = file_name(room),"/d/") < 0
         || strsrch(room_name, "/d/wizard/") == 0
         || strsrch(room_name, "/d/wuguan/") == 0
         || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/group") == 0
         || strsrch(room_name, "/d/mingjiao/lsd/") == 0
         || strsrch(room_name, "/d/mingjiao/bhd/") == 0
         || strsrch(room_name, "/d/shaolin/fumoquan") == 0
         || strsrch(room_name, "/d/xingxiu/") == 0
         || strsrch(room_name, "/d/baituo/") == 0
         || strsrch(room_name, "/d/meizhuang/") == 0
	 || present("pan tu", room))
	return 0;
	return 1;
}

string ask_job5()
{
	mapping fam;
	object pp,where,target, *living ,me , ob ,partner,*list;
	int i,j,busy_time,shen;
	string str,menpai;

	if (!me) me= this_player();
	if (!me) return 0;

	shen=me->query("shen");

	if(shen > -10000 ) return "���������ɲ���Ҫ������æ��";

	if( me->query("combat_exp") < 100000 )
		return "���ʵս����̫���˵�ɣ�����ȥ�ҿ�ʵ�ڲ�����ģ�\n";

	if((!pp=me->query("xx/partner")) && me->query("xx/pantu"))
	    return "����������һ������󣬸���ȥ�ˣ�\n"+
		   "��ֻ�ܷ�����ask ding about ��������ǰ��������ˣ����������ܵ�����ĳͷ���";

	if( me->query("xx/pantu") && ((time()-(int)me->query("xx/pantu_time"))<(12*60)) )
		return "�Ҳ��ǽ����"+pp->query("name")+"("+capitalize(pp->query("id"))+")��"+me->query("xx/pantu_place")+"ȥ����Ǹ���ͽ���";

	if(me->query_condition("gb_mission") || me->query_condition("gb_busy"))
		return "������������л��ӣ����ӵ����ؤ�������˵��";

	if( !wizardp(me) && me->query_condition("job_busy") ) {
		command("pat "+(string)me->query("id"));
		    return "������һ��������ȥ��Ϣһ����ɣ�";
	}

	if( me->query("job_name") == "����ɱ��ͽ")
	       return "������һ��������ȥ��Ϣһ����ɣ�";

	me->delete("xx/pantu_busy");

	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if(check(living[j]) ){
			target = living[j];
			str = environment(target)->query("short");
			if (str == "��Ӫ"
			 || str == HIW"����"NOR
			 || str == "��ɮ��"
			 || str == "������"
			 || str == "�ӻ���"
			 || str == "�ܵ�"
			 || str == HIR"������"NOR
			) continue;
			if( get_place(base_name(environment(target)))!="" )
				break;
		}
	}
	if (me->query_temp("xx_count") > 50) {
		me->delete_temp("xx_count");
		return "û�к��ʵĴ������ɲ����������";
	}

	if( !target )
		return "��������ô����������һ����ȥ��ɣ����һ���������Ұɡ�";

	list = filter_array(users(), (: $1->query("combat_exp")>49999 :));
	partner = list[random(sizeof(list))];

	where = environment(partner);

	if ((!environment(partner))
	 || environment(partner)->query("short")=="�һ�Դ"
	 || wizardp(partner)
	 || environment(partner)->query("short")=="����"
	 || environment(partner)->query("short")=="����"
	 || environment(partner)->query("short")=="�����˷�ͥ"
	 || ((string)partner->query("family/family_name") == "��Ĺ��" && partner->query_skill("yunu-xinjing", 1) < 101)
	 || (!interactive(partner))
	 || environment(partner)->query("no_fight")
	 || partner->query_temp("have_partner")
	 || partner->query("combat_exp") < me->query("combat_exp")/ 5
	 || partner == me
	 || partner->query_temp("user_type") == "worker" ){
		me->add_temp("xx_count",1);
		call_out("ask_job5", 0, me);
		return "";
	}
	else {
		if(!fam = (mapping)partner->query("family")) menpai="��ͨ����";
		else menpai=fam["family_name"];

		me->set("xx/pantu",1);
		me->set("xx/partner",partner);

		partner->delete("env/block");
		partner->set_temp("have_partner",1);

		busy_time = 40;
		me->set("xx/pantu_time",time());
		me->apply_condition("job_busy",busy_time);
		me->set("xx/pantu_place",get_place(base_name(environment(target)))+environment(target)->query("short"));
		if(wizardp(me)) tell_object(me,base_name(environment(target)));

		ob = new(__DIR__"pantu3");
		ob->set("xx_target", me);
		ob->set("xx_partner",partner);
		ob->set("xx_place", environment(target));

		if(random(20) != 1) {
			ob->do_copy(me,0);
			me->set("xx/pantu_super",0);
		}
		else {
			ob->do_copy(me,1);
			me->set("xx/pantu_super",1);
		}
		ob->move("/d/xingxiu/caiji_room");
		me->set("xx/pantu_obj",ob);
		command("hmm "+me->query("id"));

		log_file("job/pantu",sprintf("%8s%-10s��%5d������ʼ���ܼ�e��%d��p��%d��exp��%d\n",
			me->name(),"("+me->query("id")+")",me->query("job_time/������ͽ")+1,me->query("xx_jobe"),me->query("xx_jobp"),
			me->query("combat_exp")),me);
		log_file("job/pantu",sprintf("%8s%-10s��%d���������ܼ�e��%d��p��%d��exp��%d\n",
			partner->name(),"("+partner->query("id")+")",me->query("job_time/������ͽ")+1,partner->query("xx_jobe"),partner->query("xx_jobp"),
			partner->query("combat_exp")),me);

		tell_object(partner,HIY+"�������ɶ�������ǧ�ﴫ�������㣬��ȥ��"+me->query("xx/pantu_place")+"���"+HIM+me->name()+HIW+"("+ capitalize(me->query("id")) + ")"+HIY+"���ɱ��ͽ������\n"NOR);
		return "��˵����Ǹ��쵰��"+me->query("xx/pantu_place")+CYN"������û�����"+
			menpai+ partner->name()+"("+ capitalize(partner->query("id")) + ")һ��ȥ��������ͽ�ɡ�";
	}
}

int give_reward(object me)
{
	int e,p,t,t1,partner,high,myexp,paexp,d,low,e2= 100 + random(51),p2= 20+random(9);

	command("welcome");
	command("say �ܺã���Ϊ�����ɲ���������࣬��Ӧ�úúüν��㡣");
	command("touch "+me->query("id"));

	if(!partner = me->query("xx/partner")){
		me->delete("xx/pantu");
		me->delete("xx_job5_finished");
		me->delete("xx/panntu_place");
		me->apply_condition("job_busy",6);
		me->delete("xx/pantu_time");
		me->delete("xx/pantu_super");
		command("say �����������ɵ��൱���ã��ҷǳ������������Ϊ��");
		command("say �����Ĵ��������ֱ�ӻ���������ȥ�ˣ�");
		command("say ��ֻ�ܷ�����ǰ��������ˣ����������յ�����ĳͷ���");
		return 1;
	}

	myexp=me->query("combat_exp");
	paexp=partner->query("combat_exp");

	high=(myexp>paexp)?myexp:paexp;
	if(high==paexp)low=myexp;
	else low=paexp;
	t1 = ABS(12-(time()-(int)me->query("xx/pantu_time"))/60);
	if(t1<2)t1=2;
	if(t1>5)t1=5;

	d=ABS(high-low);

	e = 280 + random(70);

	if (me->query("xx/pantu_super"))
		e = e * (100+random(50)) / 100;

	if ( e > 500 ) e = 400 + random(100);
	p = e/5 + random(e/10);

	me->delete("xx/pantu");
	me->delete("xx_job5_finished");
	me->delete("xx/panntu_place");
	t = time()-(int)me->query("xx/pantu_time");

	me->delete("xx/pantu_time");
	me->delete("xx/pantu_super");

	me->add("job_time/������ͽ",1);
	me->add("xx_jobe",e);
	me->add("xx_jobp",p);
	me->add("combat_exp",e);
	me->add("potential",p);
	me->set("job_name","����ɱ��ͽ");

	me->clear_condition("job_busy");

	partner->add("combat_exp",e2);
	partner->add("potential",p2);
	partner->add("xx_jobe",e2);
	partner->add("xx_jobp",p2);
	partner->set_temp("have_partner",0);

	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	if ( (int)partner->query("potential", 1) > (int)partner->query("max_pot", 1) )
		partner->set("potential" , partner->query("max_pot", 1) );

	if ((string)me->query("family/family_name") == "������"
	   && me->query_skill("poison",1) < 180)
		me->improve_skill("poison", e);

	tell_object(partner,HIC"�㱻������"+CHINESE_D->chinese_number(e2)+"�㾭�飬"+CHINESE_D->chinese_number(p2)+"��Ǳ�ܣ�\n"NOR);
	tell_object(me,HIC"�㱻������"+CHINESE_D->chinese_number(e)+"�㾭�飬"+CHINESE_D->chinese_number(p)+"��Ǳ�ܣ�\n"NOR);

	log_file( "job/pantu",sprintf("%8s%-10s��%5d��������������飺%d��Ǳ�ܣ�%d���ܼ�e��%d��p��%d��exp��%d\n",
		me->name(),"("+me->query("id")+")",me->query("job_time/������ͽ"),e,p,me->query("xx_jobe"),me->query("xx_jobp"),
		me->query("combat_exp")),me);
	log_file( "job/pantu",sprintf("%8s%-10s��%5d�δ���������飺%d��Ǳ�ܣ�%d���ܼ�e��%d��p��%d��exp��%d\n",
		partner->name(),"("+partner->query("id")+")",me->query("job_time/������ͽ"),e2,p2,partner->query("xx_jobe"),partner->query("xx_jobp"),
		partner->query("combat_exp")),me);

	return 1;
}

string ask_fail()
{
	int myexp,paexp,high,low,e,d;
	object me = this_player(),partner;

	if (me->query_temp("quest/family") == "������") {
		me->delete_temp("quest");
		me->add("combat_exp", -(30+random(30)));
		me->apply_condition("job_busy", 6);
		return "�ðɣ��������ˣ��������ģ��´��ٰ��Ұɡ���";
	}

	if( !me->query("xx/pantu") )
		return "�������û���񣬷���ʲôѽ��\n";

	if(!partner=me->query("xx/partner")){
		me->delete("xx/pantu");
		me->delete("xx_job5_finished");
		me->delete("xx/panntu_place");
		me->apply_condition("job_busy", 6);
		me->delete("xx/pantu_time");
		me->delete("xx/pantu_super");
		return "�ðɣ��������ˣ��������ģ��´��ٰ���ɱ��ͽ�ɡ���";
	}

	myexp=me->query("combat_exp");
	paexp=partner->query("combat_exp");

	high=(myexp>paexp)?myexp:paexp;
	if(high==paexp)low=myexp;
	else low=paexp;

	d=ABS(high-low);

	e = 100 + random(40);

	me->delete("xx/pantu_place");
	me->delete("xx/pantu_time");
	me->delete("xx/pantu");
	me->delete("xx/partner");
	me->delete("xx/pantu_super");
	me->apply_condition("job_busy", 6+random(3));

	partner->set_temp("have_partner",0);

	me->add("combat_exp",-e/2);

	tell_object(me,HIC"�㱻�ͷ���"+CHINESE_D->chinese_number(e/2)+"�㾭�飡\n"NOR);

	log_file( "job/pantu",sprintf("%8s%-10s�����˵�%5d�����񣬼����˾���%d��\n",
		 me->name(),"("+me->query("id")+")",me->query("job_time/������ͽ")+1,e/2),me);

	return "��Ȼ�㲻��ȥ����������Ļ�����Ҫ����һЩ�ͷ��ˡ�";
}

string ask_job5_times()
{
	object ob = this_player();

	if(!ob->query("job_time/������ͽ"))
		return "�Բ���"+ob->name()+"�������û������������������أ����͸ɰɣ�";
	return ""+ob->name()+"���������ɱ����"+HIY+CHINESE_D->chinese_number((int)ob->query("job_time/������ͽ"))+NOR+"����ͽ��";
}

string ask_job4()
{
	object me=this_player();
	int shen=me->query("shen");

	if(shen > -10000 ) return "���������ɲ���Ҫ������æ��";
	if( me->query("combat_exp") < 100000 )
		return "���ʵս����̫���˵�ɣ�����ȥ�ҿ�ʵ�ڲ�����ģ�\n";
	if (me->query("family/family_name") !="������"){
		command("? "+ (string)me->query("id"));
		return "�㲻�����޵��ӣ�������������ȡ�\n";
	}
	if( me->query("combat_exp") > 2000000 )
	if (me->query("job_time/����")+me->query("job_time/������ͽ")+me->query("job_time/���ް���") > 500 )
		return "��ľ��鹻���ˣ������ñ���ȥ���ɣ�";

        if( me->query("job_name") == "����ץ����")
        	return "���ץ����ӣ�����ȥ��Ϣ��ɡ�";
	if( me->query_condition("job_busy"))
		return "�㻹æ�Ÿɱ���أ����������ɡ�";
	if(me->query_condition("gb_mission") || me->query_condition("gb_busy"))
		return "������������л��ӣ����ӵ����ؤ�������˵��";

	command("ok "+ (string)me->query("id"));
	me->set_temp("chonggu_allow",1);
	me->set_temp("xx_job4", 1);
	me->set("job_name", "����ץ����");
	me->apply_condition("job_busy", 10);
	return "�ðɣ������ڿ��Խ������ȥ�ˡ�";
}
