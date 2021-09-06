// baoxiang.c ����

#include <job_mul.h>
#include <ansi.h>
#include <get_place.h>

inherit NPC;
inherit F_MASTER;

int check(object ob);

string ask_miji();
string ask_jiaohuan();
string ask_job();
string ask_times();
string ask_fail();
string ask_fail2();
string ask_finish();
string ask_diyun();

#include "/d/suzhou/npc/lchj.h";

void create()
{
	set_name("����", ({ "bao xiang", "baoxiang" ,"bao","xiang"}));
	set("long",@LONG
����Ѫ���������������ӣ����÷�ͷ��������汩Ű֮ɫ��
����������ķ��Ź⣬�����ؽ����еĳ����ˡ�
LONG
	);
	set("title", HIR "������Ѫ���������µ���" NOR);
	set("gender", "����");
	set("class", "huanxi");
	set("age", 39);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 28);
	set("int", 15);
	set("con", 25);
	set("dex", 28);
	set("max_qi", 900);
	set("eff_jing", 300);
	set("max_jing",300);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 30000);

	set("job_npc", 1);
	set("unique", 1);
	set("no_get","���������˵̫���ˡ�\n");

	set_skill("huanxi-chan", 80);
	set_skill("literate", 60);
	set_skill("force", 80);
	set_skill("longxiang-boruo", 80);
	set_skill("dodge", 80);
	set_skill("yuxue-dunxing", 80);
	set_skill("hand", 70);
	set_skill("dashou-yin", 70);
	set_skill("claw", 70);
	set_skill("tianwang-zhua", 70);
	set_skill("parry", 80 );

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "tianwang-zhua");
	map_skill("claw", "tianwang-zhua");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	set("inquiry", ([
		"Ѫ���ؼ�" : (: ask_miji :),
		"����" : (: ask_jiaohuan :),
		"Ѫ������" : "������ʦ�������������������У�����������\n",
		"����" : "��˵������ʦ��Ѫ������ɣ������пɲ����׼�����\n" ,
		"����" : "����������Ҳ�Ǵ˵����ˣ��л������������ϡ�\n",
		"С�" : "�������ҵ�֪����֪������Ȥ���ڣ���ʲô��Ϣ���ǽ���������\n",
// xueshan job move to baoxiang 2003.5.12
		"����":		(: ask_job :),
		"job" :		(: ask_job :),
		"����":		(: ask_times :),
		"����":		(: ask_times :),
		"����" :	(: ask_fail :),
		"fangqi":	(: ask_fail :),
		"ʧ��" :	(: ask_fail2 :),
		"shibai":	(: ask_fail2 :),
		"���":		(: ask_finish :),
		"finish":	(: ask_finish :),
// add quest by tangfeng
		"����" : (: ask_diyun :),
		"���վ�" : random(2)?"��˵������ī��÷���ϵ��ڹ��ķ���":"�Ҽǵ������֮�ھͿ������վ��ڹ��ķ���",
		"����ɽ" : "÷�����ϵĵ��ӡ�",
		"�Դ�ƽ" : "÷�����ϵĵ��ӡ�",
		"�ݳ���" : "÷�����ϵĵ��ӡ�",
		"÷����" : "����ī��÷���ϣ���ϧ����ԩ������",
	]));
	set("miji_count", 1);

	create_family("������", 12, "����");
	set("class", "huanxi");

	setup();
	carry_object("/d/xueshan/npc/obj/gongde-jiasha")->wear();

	add_money("silver",10);
}

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
		reincarnate();
}
string ask_diyun()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return ""+RANK_D->query_respect(me) +"�����Լ�С��ͨ���ɣ�";
	}
	if(me->query(QUESTDIR1+"over" ))
	{
	   command("claw "+me->query("id"));
	   return "�Ǹ����ͷ��С�Ӿ�Ȼ�ܹ������ԭ��Ϻ�׺���ʦ������ôͻȻ��ô�����ˣ�";
	}
	if(!me->query(QUESTDIR1+"start" ))
	{
	   command("? "+me->query("id"));
	   command("say");
	   return "������˭��";
	}
	if(!me->query_temp(QUESTDIR1+"start" ))
	{
	   command("say");
	   command("claw "+me->query("id"));
	   return "������˭��";
	}
	if(me->query_temp(QUESTDIR1+"askbaoxiang"))
	{
	   command("en");
	   message_vision(HIY"$N����¶���Źֵ���ɫ��\n", ob);
	   return "�Ǹ����ͷ��С������Ӧ����ѩɽѩ��һ����";
	}
	command("sigh");
	message_vision(HIY"$N����¶�����ߵ���ɫ��\n", ob);
	me->set_temp(QUESTDIR1+"askbaoxiang",1);
	return "��˵�Ǹ����ͷ����������ʦ��ץȥ�ˣ���Ҳ��֪�����������";
}
void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "������") {
		command("say"+ RANK_D->query_respect(ob) +"���Ǳ��µ��ӣ������ﵷʲô�ң���");
		return;
	}
	if ((int)ob->query_skill("huanxi-chan", 1) < 50) {
		command("say ��ϲ���Ǹ����书֮���������ڼ������ɡ�");
		command("say"+ RANK_D->query_respect(ob) + "�ٰ�����ͨ��������������б��ŵ��ķ��ɡ�");
		return;
	}
	if ((string)ob->query("class") != "huanxi") {
		message_vision("�����˿���ͷ�������������Լ��Ĺ�ͷ��",this_player());
		command("say �㻹û���ң����ܱ�ʾ���������̷ϲ���Ҳ������㡣");
		command("say ��λ" + RANK_D->query_respect(ob) + "�������¾��ģ������̷��ҷ��������Ұɡ�");
		return;
	}
	command("say �ðɣ��Ժ���ͺú��̷��ү�Ұɡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", HIR "������Ѫ���ŵ���������" NOR);
}

string ask_miji()
{
	this_player()->set_temp("jiaohuan",1); 
	return  "Ѫ���ؼ��Ǳ���һ�����飬�Ǳ�����ǰһλ��ɮ��¼�����ģ�\n"+
		"������Ҫ��һ�׵��������׵�����������...���������ʲô���ؼ�����\n"+
		"������һ�û���꣬�������ġ�\n" ;
}

string ask_jiaohuan()
{
	if ( this_player()->query_temp("jiaohuan")) {
		this_player()->delete_temp("jiaohuan");
		this_player()->set_temp("miji",1);
		return "����ʲô���书����Ҫ���أ�������ʲô�������һ���";
	}
	else {
		message_vision("�����Ի�Ŀ��˿�$N��\n",this_player());
	}
}

int accept_object(object who, object ob)
{
	object obj;
        
	if( !who || environment(who) != environment() ) {return 0;}
	if ( !objectp(ob) ) {return 0; }
	if ( !present(ob, who) ) return notify_fail("��û�����������");
	if (! who->query_temp("miji")) return 0;

	if ((string)ob->query("id") == "chungong tu" ){
		obj=unew(MISC_D("xuedao-miji"));
		command("ah");
		message_vision("����ϲ��ü����Ц�������㵸��\n",this_player());
		command("say ������Ǹ��������������㵽�ģ�̫������");
		if(!clonep(obj)) {
			command("say �ã�����ô����!\n");
			remove_call_out("nothing");
			call_out("nothing", 2, who);
			remove_call_out("destroying");
			call_out("destroying", 1, this_object(), ob);
			return 1;
		}
		if(clonep(obj) && ob->violate_unique()){
			destruct(obj);
			command("say �ã�����ô����!\n");
			remove_call_out("nothing");
			call_out("nothing", 2, who);
			remove_call_out("destroying");
			call_out("destroying", 1, this_object(), ob);
			return 1;
		}
		message_vision("��������$N���ڣ��Ͻ��Ѵ���ͼ���ڻ��У���Ѫ���ؼ�����$N���С�\n",this_player());
		obj->move(who);
		who->delete_temp("miji");
		command("say �ã�����ô����!\n");
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}
	else {
		command("say ������뻻������������!");
		return 0;
	}
}

void destroying(object me, object obj)
{
	if(!obj) return;
	destruct(obj);
}

void nothing(object me)
{
	if (!me) return;
	message_vision("���������ڻ����������͵����˰��죬ʲôҲû�ͳ�����\n", me);
	command("say ���ˣ�������Ѫ���ؼ��Ѿ����˱����ˡ�");
	command("say ���㵹ù���Ȿ����ͼ����Ƚ���ҿ�����ɡ�"); 
	command("shrug");              
}

void init()
{
	object ob;
	ob = this_player();
	if( ob->query("gender")=="Ů��"
	 && ob->query("family/family_name") != "������" 
	 && !ob->query("xs/girl")){
		if( ob->query_per() >= 20 ){
			ob->add_busy(1);
			call_out("meeting1", 0, ob);
		}
		else {
			ob->add_busy(1);
			call_out("meeting2", 0, ob);
		}
	}
}

void meeting1(object ob)
{
	if (ob) {
		message_vision(HIY"����ͻȻ����$N��ǰ����ס��ȥ·��\n"NOR,ob);
		message_vision(HIY"�������´�����$N���ٺ���Ц��������\n"NOR,ob);
		command("say ��λ"+RANK_D->query_respect(ob)+"���ߵ���ô������������ȥѽ��");
	}
}

void meeting2(object ob)
{
	if (ob) {
		message_vision(HIY"����ͻȻ����$N��ǰ����ס��ȥ·��\n"NOR,ob);
		message_vision(HIY"�������´�����$N�������ֳ�ʧ������ɫ�����һƲ��\n"NOR,ob);
		command("say ��λ"+RANK_D->query_respect(ob)+"��ô������˳�ª��ʵ�����˴�ʧ������");
	}
}

string ask_finish()
{
	object me = this_player();
	if( !me->query("xs/girl")) {
		command("? "+ (string)me->query("id"));
		return "��ʲô��˼��";
	}

	if( !me->query_temp("xs/finish")) {
		command("kick "+ me->query("id"));
		command("consider "+ me->query("id"));
		return "��С��û��ɣ����뵽����үү������ƭ��ƭ�Ȱ���";
	}

	command("hehe");
	command("say ��������������������ˣ��������үү���£�����үү���������ġ�");
	if (me->query("xs/girl_super")) {
                   TASKREWARD_D->get_reward(me,"ѩɽ",-1,0,2,18+ random(4),0,0,0,this_object());
      
                                                            }
else
                    TASKREWARD_D->get_reward(me,"ѩɽ",-1,0,0,6+random(3),0,0,0,this_object());

	me->delete("xs/girl");

	me->clear_condition("job_busy");
	me->clear_condition("xs_job");
	me->delete_temp("xs/finish");
	me->apply_condition("xs_job", 10 );

	me->delete("xs/girl_time");
	me->delete("xs/girl_ob");
	me->delete("xs/girl_super");
	me->delete("xs/cant");
me->set("job_name","ǿ����Ů");
	me->add_temp("xs/xs_job", 1);

	if ((string)me->query("family/family_name")=="������"
	  && me->query_skill("huanxi-chan",1) < 200)
                me->improve_skill("huanxi-chan", me->query_skill("huanxi-chan",1));

	me->delete("xs/girl_place");

	return "�úøɣ�����үү��ϲ����ģ��ٺ٣�";
}

string ask_job()
{
	object target, *living , me = this_player() , ob , beauty;
	int i,j;
	string str;

	if( me->query("combat_exp") < 100000 )
		return "���ʵս����̫���˵�ɣ�����ȥ�ҿ�ʵ�ڲ�����ģ�";

	if( !(wizardp(me) && me->query("env/test")) && me->query("xs/girl") && ((time()-(int)me->query("xs/girl_time"))<(12*60)) )
		return "�Ҳ��ǽ��㵽"+me->query("xs/girl_place")+"ȥ������үү����Ů���";

	if( !(wizardp(me) && me->query("env/test")) && me->query("job_name") == "ǿ����Ů")
		return "��Ҫ����������үү����һ�ߴ���ȥ��";

	if( !(wizardp(me) && me->query("env/test")))
	if( me->query_condition("job_busy") || me->query_condition("xs_job")) {
		if ( me->query("job_name") == "ǿ����Ů") {
		    command("kick "+(string)me->query("id"));
		    return "��Ҫ����������үү����һ�ߴ���ȥ��";
		}
		else
		    return "�����Ǹ����ı�Ǯ����ͬ־���㻹����ЪϢһ����ɡ�";
	}
	me->delete("xs/girl_busy");

	if(me->query("shen") > -10000 && !wizardp(me)){
		return "�ҿ��㲻���ĺ�������үү�Ҳ�ϲ����";
	}
	if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
		return "����������û�и���������㻹���ȴ����������������˵�ɡ�";


	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if(check(living[j]) ){
			target = living[j];
			str = environment(target)->query("short");
			if( str == "��ɮ��"
			 || str == HIR"������"NOR
			 || str == "��շ�ħȦ"
			 || str == HIB"����Ժ"NOR) continue;
			if( get_place(base_name(environment(target)))!="" )
				break;
		}
	}

	if( !target )
		return "�����û��˵��ʲô��������Ů�����һ��������ɡ�";

	me->apply_condition("job_busy", 30);
	me->apply_condition("xs_job", 30);
	me->set("xs/times", uptime());
	me->set("xs/girl",1);
	me->set("xs/girl_time",time());
	me->set("xs/girl_place",get_place(base_name(environment(target)))+environment(target)->query("short"));

	beauty = new("/d/xueshan/npc/gbeauty");
	beauty->set("long", beauty->query("long")+
		"��������Ѫ������Ҫ��"+me->query("name")+"("+capitalize(me->query("id"))+")ǿ������Ů��\n");
	beauty->move(environment(target));
	me->set("xs/girl_ob",beauty);
//	beauty->move("/d/xueshan/emptyroom");

	ob = new("/d/xueshan/npc/guard");
	ob->set("target", me->query("id"));
	ob->set("beauty", beauty);
	if(wizardp(me)) tell_object(me, base_name(environment(target))+"\n");
	me->set("xs/cant",0);

    if(random(3) != 1 || me->query("combat_exp") < 1000000 ) {
		ob->do_copy(me,0);
		me->set("xs/girl_super",0);
	}
	else {
		ob->do_copy(me,1);
		me->set("xs/girl_super",1);
                     if(wizardp(me)){
                          write("�Ѷȵȼ�:Super!\n"NOR);
                      }
		if ( (me->query("combat_exp") > 1000000) && (random(3)==1) )
		    me->set("xs/cant",1);
	}
	beauty->set("guard", ob);
	ob->move(environment(target));
//	ob->move("/d/xueshan/emptyroom");
	beauty->set_leader(ob);

	if( !objectp( present("hehuan san", me)) ) {
		ob = new("/d/xueshan/npc/hhs");
		ob->move(me);
		message_vision("�����$Nһ�������ϻ�ɢ��\n",me);
	}
	command("walkby");
	command("whisper " + me->query("id")+ " ��˵���"+me->query("xs/girl_place")+GRN"�������˸�Ư����С椣���ȥ����Ū����");
/*
	log_file( "job/xueshan",sprintf("%8s%-10s��ʼ��%5d��ѩɽ����Ŀ�꣺%s��Ŀǰ���飺%d\n",
		me->name(), "("+me->query("id")+")", me->query("job_time/ѩɽ")+1,
		me->query("xs/girl_place"), me->query("combat_exp")),me);
*/
	return "������үү�ɻ��ȥ�ٻء�";
}

string ask_fail()
{
	int i;
	object me = this_player();

	if( !me->query("xs/girl") )
		return "�������û���񣬷���ʲôѽ��";
	if( !me->query("xs/girl_super") )
		return "��ô�򵥵���������ô���Է����أ���ȥ�ɣ�";
	if( me->query("xs/cant") )
		return "���У��е�רҵ����ò��ã����ѵ������Ͳ���������ô�Ե����Ҹ����EXP��";

	me->delete("xs/girl");
	me->delete("xs/girl_time");
	me->delete("xs/girl_ob");
	me->delete("xs/girl_super");
	me->delete("xs/cant");
	me->add("combat_exp", -(30+random(40)));
	i = 40 - me->query_condition("xs_job");
	if ( i >= 9 )
		me->apply_condition("job_busy", 1);
	else
		me->apply_condition("job_busy", 9 - i);
	me->apply_condition("xs_job", 3);
	log_file( "job/xueshan",sprintf("%8s%-10s�����˵�%5d����������(%s)��\n",
		me->name(),"("+me->query("id")+")",me->query("job_time/ѩɽ")+1, me->query("xs/girl_place")), me);
	me->delete("xs/girl_place");
	return "��������ǱȽ����ѣ����겻��Ҳ����ȫ���㡣";
}

string ask_fail2()
{
	object me = this_player();
	int i;

	if( !me->query("xs/girl") )
		return "�������û����ʧ��ʲôѽ��";

	command("disapp "+me->query("id"));

	me->delete("xs/girl");
	me->delete("xs/girl_time");
	me->delete("xs/girl_ob");
	me->delete("xs/girl_super");
	me->delete("xs/cant");
	me->add("combat_exp", -(30+random(40)));

	i = 40 - me->query_condition("xs_job");
	if ( i >= 9 )
		me->apply_condition("job_busy", 1);
	else
		me->apply_condition("job_busy", 9 - i);

	me->apply_condition("xs_job", 3);

	log_file( "job/xueshan",sprintf("%8s%-10s��%5d������ʧ��(%s)��\n",
		me->name(),"("+me->query("id")+")",me->query("job_time/ѩɽ")+1, me->query("xs/girl_place")),me);
	me->delete("xs/girl_place");
	return "��ú÷�ʡһ��ȥ��";
}

string ask_times()
{
	object ob = this_player();

	if(!ob->query("job_time/ѩɽ"))
		return "�Բ���"+ob->name()+"�������û������������������أ����͸ɰɣ�";

	return ""+ob->name()+"�����Ѿ����������үү"+CHINESE_D->chinese_number((int)ob->query("job_time/ѩɽ"))+"����Ů��";
}

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("quest")
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/xueshan/") == 0
         || strsrch(room_name, "/d/shaolin/fumoquan") == 0
         || strsrch(room_name, "/d/wudang/houshan/") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}
void die()
{
	object ob;
	if (!query_temp("living"))
	{
		ob = new("/kungfu/class/xueshan/baoxiang");
		ob->move("/d/xueshan/shanlu4");
	}
	::die();
}
