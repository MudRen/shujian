// h7g.c ���߹�
// Looklove@SJ 2000/8/25
// Looklove Modify at 2001/1/19
// Looklove Modify at 2001/4/7
// Looklove Modify at 2001/5/3
// River@SJ For ���˭������÷ job 3.29.2002
// Update By lsxk@hsbbs ����ͨ����Ʒ��߽�kanglong���� 2007/7/18
//Update By action@SJ 2008/12/5

inherit NPC;
#include <job_mul.h>
#include <ansi.h>
#include <get_place.h>
#include "h7g.h";

int ask_up();
int pass_chuanwei(object me, object ob);
string ask_job();
string ask_finish();
string ask_fangqi();

string *no_kill_list = ({
	"mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int filldata(object obj1)
{
	if(wiz_level(obj1))
		return 0;
	if(!environment(obj1))
		return 0;
	else return 1;
}

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || member_array(ob->query("id"), no_kill_list) != -1
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("quest")
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/gb/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}

void create()
{
	object ob;
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
	set("nickname", HIY"��ָ��ؤ"NOR);
	set("gb/bags",10);
	set("gender", "����");
	set("age", 65);
	set("per",24);
	set("long", "������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "friendly");
	set("no_bark",1);
	set("dgb/wugou",6);

	set("str", 40);
	set("con", 35);
	set("dex", 30);
	set("int", 35);

	set("max_qi", 11000);
	set("max_jing", 7600);
	set("neili", 21000);
	set("max_neili", 18500);
	set("jiali", 150);
	set("eff_jingli", 8000);
	set("combat_exp", 5400000);

	set_skill("force", 370);
	set_skill("huntian-qigong", 370);    // ��������
	set_skill("strike", 380);            // �����Ʒ�
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("literate", 200);           // ��д
	set_skill("dodge", 350);             // ��������
	set_skill("xiaoyaoyou", 350);        // ��ң��
	set_skill("parry", 380);             // �����м�
	set_skill("stick", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("bangjue", 200);            // ����
	set_skill("dagou-zhen", 200);	     // ����
	set_skill("lianhua-zhang", 340);      // ������
	set_skill("stealing", 200);           // hehe

	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("stick", "dagou-bang");
	prepare_skill("strike", "xianglong-zhang");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "strike.xiao" :),
        	(: perform_action, "strike.paiyun" :),
        	(: perform_action, "stick.chan" :),
		(: perform_action, "stick.zhuan" :),
        	(: exert_function, "huntian" :),
        	(: exert_function, "shentong" :),
	}));
	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n"NOR,
		CYN"���߹�˵�������϶���Ĺ����ռ������������ҵ����취�Ը�������\n"NOR,
		CYN"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n"NOR,
	}));

	set("inquiry", ([
		"�϶���" : "�϶�������ҵ�����ͷ���������˳�������ŷ���塣\n",
		"ŷ����" : "�����ҵ�����ͷ���������˳�������\n",
        	"����" : "���...���...\n",
        	"����" : "�����ҵĺ�ͽ���������˱��˵㡣\n",
        	"����" : "��СѾͷ���Ǹ�����������Ŀ��治����\n",
        	"��ҩʦ" : "����������ѧ��ţ������һ��Ǹ�ϲ�����Ǹ�СѾͷ��\n",
        	"��а" : "����������ѧ��ţ������һ��Ǹ�ϲ�����Ǹ�СѾͷ��\n",
        	"�ϵ�" : "������壬���Ҹ��ʡ�\n",
        	"������" : "�ǿ��Ǹ���ѧ��ţ��Ͻл��ɲ��������ܡ�\n",
        	"����ͨ" : "���������ںܶ�����������������Ϊ�Լ�����������������\n",
        	"ؤ��" : "����ؤ�ﶼ��֪�����ҿ����е��㶷�ˣ�\n",
        	"�򹷰�" : "���...���...������Σ�\n",
        	"������" : "û�±��Ҵ�����С����һ�������㡣\n",
        	"������" : "û�±��Ҵ�����С����һ�������㡣\n",
        	"rumors" : "���û��˵ʲô��Ϣ��\n",
		       "�����л�" : "û�±��Ҵ�����С����һ�������㡣\n",
        	"�л���" : (: ask_ji :),
        	"�����޹�" : (: ask_wugou :),
        	"��λ":    (: ask_up :),
        	"���˭������÷": (: ask_job :),
        	"job" : (: ask_job :),
        	"finish": (: ask_finish :),
        	"���" : (: ask_finish :),
        	"����" : (: ask_fangqi :),
        	"fangqi" : (: ask_fangqi :),        	
	]));

	create_family("ؤ��", 17, "����");
	set_temp("apply/damage", 70);
	set_temp("apply/dodge", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/armor", 120);
	setup();

	if (clonep()) {		
		object *ob_list = filter_array(users(), (: filldata :));
		for (int i=0;i<sizeof(ob_list);i++){
			if (ob_list[i]->query_temp("gb_chuanwei") ){
				set("long", "������ؤ���ǰ�������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
				set("title","ؤ��ǰ����");
				break;
			}
		}
		ob = unew(BINGQI_D("yuzhu_bang"));
		if (!ob) ob = unew(BINGQI_D("zhubang"));
		ob->move(this_object());
		ob->wield();
		carry_object(ARMOR_D("bainayi"))->wear();
		carry_object(ARMOR_D("shoes"))->wear();
		carry_object(__DIR__"obj/gb_budai10")->wear();
	}
}

void reset()
{	
	if (clonep() ) {
		int i = 0;
		object *ob_list = filter_array(users(), (: filldata :));
		object ob = unew(BINGQI_D("yuzhu_bang"));
		for (i=0;i<sizeof(ob_list);i++){
			if (ob_list[i]->query_temp("gb_chuanwei") ){
				set("long", "������ؤ���ǰ�������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
				set("title",CYN"ؤ��ǰ����"NOR);
				break;
			}
		}
		if(i==sizeof(ob_list))
		{
			set("long", "������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
			delete("title");
		}
		if(ob){
			ob->move(this_object());
			command("unwield all");
			command("wield yuzhu bang");
		}		
	}
}

void attempt_apprentice(object ob)
{
	if ( ob->query("job_time/ؤ��",1) < 400 && ob->query("job_time/ץ��") < 400){
		command("say  ���ҵĵ���ҪΪؤ�����������" + RANK_D->query_respect(ob) + "�ڰ��еĻ����ƺ�������һЩ��\n");
		return;
	}
	if ( !ob->query("gb/bags") ) {
		command("say " + RANK_D->query_respect(ob) + "������һ��Ҳû�У���������ؤ����Ӱɣ�\n");
		return;
	}
	if ( ob->query("gb/bags")<6) {
		command("say " + RANK_D->query_respect(ob) + "�ڰ���ְλ̫�ͣ������������ɡ�\n");
		return;
    	}
	command("chat ���������Ͻл�����֮ǰ�����ҵ�"+ob->name()+"����һ������֮��,ؤ���������ˡ�\n");
	command("recruit " + ob->query("id"));
	ob->set("class", "beggar");
	ob->set("gb/fenduo","�ܶ�");

	if (!ob->query("gb/baih7g")){
		ob->set("gb/baih7g",ob->query("combat_exp"));
		ob->set("title",HIY "ؤ����߹��״�����" NOR);
	}
	return;
}

int ask_up()
{
	object obj1, me=this_player(),ob=this_object();
	int max, i, skill, bag = me->query("gb/bags");
	mixed *ob_list;

	skill = me->query_skill("xianglong-zhang",1);
	
	if( me->query_temp("gb_chuanwei") ){
		command("say " + RANK_D->query_respect(me) + "�Ѿ���ؤ��������ο��������ҿ���Ц��\n");
		return 1;
	}	
	if( !me->query("gb/bags")){
		command("say " + RANK_D->query_respect(me) + "����ؤ�������������˻���֪�Ӻ�˵��\n");
		return 1;
	}
	if( bag < 9 ){
		command("say ���ڰ��е�λ̫�ͣ���λ��������޷�˵���ڵ��ӡ�\n");
		return 1;
	}
	if ( (me->query("job_time/ؤ��") + me->query("job_time/ץ��")) < 2000){
		command("say " + RANK_D->query_respect(me) + "�ڰ��еĻ����ƺ�������һЩ�����������۷��ڵ��ӡ�\n");
		return 1;
	}
	if( me->query("shen") < 1500000){
		command("say " + RANK_D->query_respect(me) + "���������������������쵼ؤ��������ӡ�\n");
		return 1;
	}
	
	if(mapp(me->query("job_time")))
		me->set("job_time/��Ч����",me->query("job_time/���ϳ�")+me->query("job_time/��ɱ")+me->query("job_time/��Ħ��"));
	
	if( me->query("job_time/��Ч����") < 500) {
		command("say ��ؤ���������������ɣ�"+RANK_D->query_respect(me)
		+"Ӧ��Ϊ��Ϊ������㹱�ײźá�");
		return 1;
	}		
	if( me->query_skill("dagou-bang",1) < 280 || me->query_skill("xianglong-zhang",1) < 280 ){
		command("say �򹷰����ͽ���ʮ��������ؤ���洫������" + RANK_D->query_respect(me) + "���ⷽ�����Ϊ�Ƿ��Բ���һ�㡣\n");
		return 1;
	}
	if( !present("yuzhu bang",ob) )	{
		command("say �ҵ������������ȥ�ˣ����ˣ����¿�û�취��λ�ˡ�");
		return 1;
	}

	ob_list = users();
	ob_list = filter_array(ob_list, (: filldata :));
	max=sizeof(ob_list);
	for (i=0;i<max;i++){
		obj1 = ob_list[i];
		if (obj1->query_temp("gb_chuanwei") ){
			command( "say ���Ѿ��Ѱ���֮λ����" + obj1->query("name") +"�ˡ�\n" ) ;
			return 1;
		}
	}
	command("look "+me->query("id"));
	command( "say �������²����ȿ�������书��" );

	if ( !pass_chuanwei(me, ob ) ) return 1;
	if ( !pass_chuanwei(me, ob ) ) return 1;
	if ( !pass_chuanwei(me, ob ) ) return 1;
	if ( !pass_chuanwei(me, ob ) ) return 1;
	if ( !pass_chuanwei(me, ob ) ) return 1;
	if ( !pass_chuanwei(me, ob ) ) return 1;
	if ( !pass_chuanwei(me, ob ) ) return 1;

	me->set_temp("title",HIR "ؤ���ʮ�˴�����" NOR);

	command("chat �Ͻл����ս�ؤ�����֮λ����"+me->query("name")+"��������ؤ���������ˡ�");
	message_vision("���߹�����$Nһ���������\n",me);
	me->set_temp("gb_chuanwei",1);
	me->add_temp("apply/strength", random(skill/10));//add up bl ciwei
	present("yuzhu bang", ob)->move(me);
	
	ob->set("long", "������ؤ���ǰ�������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	ob->set("title",CYN"ؤ��ǰ����"NOR);
	return 1;
}

int pass_chuanwei(object me, object ob)
{
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);

	if (!present(me,environment(ob)) || me->query("qi") <= 0
	|| me->query("jing") <= 0 || me->query("jingli") <= 0){
		command("say �书���֮���δ����²�����");
		ob->reincarnate();
		return 0;
	}
	return 1;
}

string ask_job()
{
	object me, ob, *living, target;
	string str, food, food_id_list;
	string *food_name = ({"�������","С�����","Сţ����","�����","����"});
	string *food_id = ({"yanggao zuotun", "xiaozhu erduo", "xiaoniu yaozi", "zhangtui rou", "tu rou"});
	string *food_type;
	object objwhere, obj;
	mapping food_type_list;
	mapping skills;
	string *sk;
	int i, j, x, y, z, p;

	me = this_player();

	if (me->query("menggu"))
		return "�ߣ����������ɹţ�������ʲô��";

	if (me->query_temp("potjob/job") && !wizardp(me))
		return "�ţ��Ҳ��Ǹ��������𣬿�ȥȡԭ�ϰ��������������ˣ�";
/*
	if (me->query("job_name") == "" && !wizardp(me))
		return "�����ڲ������㻹����ȥ��Ϣһ��ɡ�";
*/
	if (me->query("combat_exp") < 100000 )
		return "��λ" + RANK_D->query_respect(me) + "�书δ�ɣ�����ȥ�����������Ͻл����ҿɲ�̫���ġ�";

	skills = me->query_skills();
	if (mapp(skills)){
		sk = keys(skills);
		for (i=0; i < sizeof(sk); i++)
			if (skills[sk[i]] > (me->query("max_pot") - 90) && sk[i] != "beauty" && SKILL_D(sk[i])->type2() != "worker")
//			if (skills[sk[i]] > (me->query("max_pot") - 90) && SKILL_D(sk[i])->type() != "knowledge" && SKILL_D(sk[i])->type2() != "worker")
				return "���"+to_chinese(sk[i])+"�ȼ������ˣ��޷�������������ˡ�";
	}

	if ( me->query("potential") >= me->query("max_pot") && !wizardp(me))
		return "��λ" + RANK_D->query_respect(me) + "��Ǳ���Ѿ���ô���ˣ�������ȥ���������ɣ�";

	if ( me->query_condition("job_busy") || me->query_condition("pot_job"))
		return "�����ڲ������㻹����ȥ��Ϣһ��ɡ�";

	me->delete_temp("potjob");
	command("say �⡸���˭������÷���ǻ������СѾͷƬ�������Ͻл��ӳԵ�һ���ˣ�\n"+
		"��ƭ���Ͻл��ӽ��˹����Ǹ�ɵС��һ�׽���ʮ���ơ������˵����Ҳ�򵥣�����������\n"+
		"С����ƴ�ɣ�һ����������Σ�һ����С����䣬һ����Сţ���ӣ�����һ����������\n"+
		"��������һ�𡣲�˵�ˣ���˵�ˣ���ˮ�������ˡ�");

	command("taste");

	for(z=0; z < 5; z ++){
		me->set_temp("potjob/food_type/"+ food_name[z], food_id[z]);
	}

	food_type_list = me->query_temp("potjob/food_type");

	y = random(4) + 2;
	for (x = 0; x < y; x ++){
		living = livings();
		for (i=0;i < sizeof(living);i++){
			j = random(sizeof(living));
			if (!j || j == sizeof(living) -1) continue;
			if(check(living[j]) ){
				target = living[j];
				objwhere = environment(target);
				str = objwhere->query("short");
				if (!sizeof(objwhere->query("exits"))
				|| str == "��ɮ��"
				|| str == HIR"������"NOR
				|| str == "ɮ��"
				|| str == "��Ϣ��"
				|| str == "����"
				|| str == "���"
				|| str == "Ů��Ϣ��"
				|| str == "����Ϣ��"
				|| str == "��շ�ħȦ" ) continue;
				if( get_place(base_name(environment(target)))!="" ) break;
			}
		}

		if( !target )
			return "��������ʱ���������㻹����ȥ��Ϣһ��ɡ�";

		p = random(sizeof(food_name));

		food = food_name[p];
		food_id_list = food_id[p];

		food_type = me->query_temp("potjob/type");

		if ( ! sizeof(food_type))
			me->set_temp("potjob/type", ({ food }));
		else {
			for(z=0; z < 5; z ++){
				if (member_array(food, food_type) != -1) {
					food = food_name[z];
					food_id_list = food_id[z];
				}
			}
			food_type = sort_array(food_type + ({ food }), 0);
			me->set_temp("potjob/type", food_type );
		}
		ob = new(__DIR__"pot_target");
		ob->set_temp("target", me);
		ob->set_temp("food_name", food);
		ob->set_temp("food_id", food_id_list);
		ob->move(objwhere);
		for (i=0; i<5; i++)
			ob->random_move();
		obj = new(__DIR__"obj/pot_food");
		obj->set_name(food, ({ food_id_list }));
		obj->set("long", "����һ��"+obj->query("name")+"��������ζ������\n");
		obj->set_temp("food_id", food_id_list);
		obj->move(ob);
		if (me->query_temp("potjob/food_type/"+food))
			me->delete_temp("potjob/food_type/"+food);
		if (strsrch(file_name(environment(ob)), "/d/zhiye/") >= 0
		 || strsrch(file_name(environment(ob)), "/d/group/") >= 0){
		 	if ( environment(ob)->query("outdoors"))
				me->set_temp("potjob/pot_job_place/"+ ob->query("name"), environment(ob)->query("outdoors")+environment(ob)->query("short"));
		 	else if ( environment(ob)->query("indoors"))
				me->set_temp("potjob/pot_job_place/"+ ob->query("name"), environment(ob)->query("indoors")+environment(ob)->query("short"));
			else me->set_temp("potjob/pot_job_place/"+ ob->query("name"), environment(ob)->query("short"));
		}
		else me->set_temp("potjob/pot_job_place/"+ ob->query("name"), get_place(base_name(environment(ob)))+environment(ob)->query("short") );
		me->set_temp("potjob/for_menu/"+ ob->name(), food);
		command("whisper "+ me->query("id")+" ��˵"+ me->query_temp("potjob/pot_job_place/"+ob->query("name")) +GRN"��"+ob->name()+"������"+food+"�������ȥ�����ɣ�");
	}

	me->set_temp("potjob/do_time", y);
	me->set_temp("potjob/time", uptime());
	me->set_temp("potjob/job",1);
	me->apply_condition("pot_job", 6);
	me->apply_condition("job_busy", 6);

	if ( !present("hong's menu", me)){
		new(__DIR__"obj/pot_paper")->move(me);
		message_vision("$N����$nһ������������������˭������÷���Ĳ��ס�\n", this_object(), me);
	}

	p = sizeof(keys(food_type_list));

	if ( p > 0 ){
		for(z=0; z < p; z ++){
			food = keys(food_type_list)[z];
			food_id_list = values(food_type_list)[z];
			obj = new(__DIR__"obj/pot_food");
			obj->set_name(food, ({ food_id_list }));
			obj->set("long", "����һ��"+obj->query("name")+"��������ζ������\n");
			obj->set_temp("food_id", food_id_list);
			obj->set_temp("job_id", me);
			obj->move(me);
			me->set_temp("potjob/be_get/"+food, 1);
		}
		return "�������Ѿ���Щԭ�ϣ��ȸ��㣬�������ȥ�Ұɣ�";
	}
	else
		return "����������ʲôԭ�϶�û�У������ٰ��������ɡ�";
}

string ask_finish()
{
	object me = this_player();
	object ob;
	int pot, i, times;

	if ( !me->query_temp("potjob/job"))
		return "���н���ȥ��ʲô�������ʲô����";

	if ( !me->query_temp("potjob/finish"))
		return "���������ˣ���";

	if ( ! ob =(present("yudi luomei", me)))
		return "������ˣ���ô�����أ�";

	destruct(ob);
	message_vision(HIY"$N�ӹ�$n���ġ����˭������÷�����������������ϣ���Ц�������տɴ󱥿ڸ��ˡ�\n"NOR, this_object(), me);

	command("pat "+ me->query("id"));
	i = me->query_temp("potjob/do_time");
	pot = 50 + i * 100 + random(50);
// �Ժ�ȥ��
	if( me->query("max_neili") < 3500)
		pot += pot/2;
		
       	/*�������ƿ�ʼ*/
        if (me->query("registered")==3){
            		pot = pot * H7G_JOB_MUL * VIP_MUL /10000;
		}
		else
		{
           		pot = pot * H7G_JOB_MUL /100;
		}
		/*�������ƽ���*/ 


	tell_object(me, HIW"���߹�ָ������һЩ��ѧ�ϵ��Խ�������"+chinese_number(pot)+"��Ǳ�ܡ�\n"NOR);
	times = uptime() - me->query_temp("potjob/time");
	me->delete_temp("potjob");
	me->add("potential", pot);
	me->add("job_time/���߹�",1);
	GIFT_D->check_count(me,this_object(),"���߹�");
	log_file("job/zuocai", sprintf("%8s%-10s ������ˣ��õ�%3d��Ǳ�ܣ�ʱ�䣺%d",
		me->query("name"), "("+me->query("id")+")", pot, times), me);
	return "�������´�������С�Ӹ��Ͻл������ˡ�";
}

string ask_fangqi()
{
	object me = this_player();
	object meat1, meat2, meat3, meat4, meat5, meat6;
	meat1 = present("yanggao zuotun", me);
	meat2 = present("xiaozhu erduo", me);
	meat3 = present("xiaoniu yaozi", me);
	meat4 = present("zhangtui rou", me);
	meat5 = present("tu rou", me);
	meat6 = present("yudi luomei", me);

	if ( ! me->query_temp("potjob/job"))
		return "���н���ȥ��ʲô�������ʲô����";

	if ( meat1 ) destruct(meat1);
	if ( meat2 ) destruct(meat2);
	if ( meat3 ) destruct(meat3);
	if ( meat4 ) destruct(meat4);
	if ( meat5 ) destruct(meat5);
	if ( meat6 ) destruct(meat6);

	command("nod "+ me->query("id"));
	me->delete_temp("potjob");
	return "��Ȼ�����ˣ�Ҳ�Ͳ���ǿ���ˡ�";
}

void dest(object obj)
{
	if(!obj) return;
	destruct(obj);
}

int accept_object(object me, object obj)
{
	object ob_yzz, ob = this_object();
   object ob_yywzk;

	if (obj->query("food_supply") <= 0) return 0;
	if ((string)obj->query("name") != "�л���" || me->query_temp("marks/get-ji")){
		command("say �Ͻл���" + (string)obj->query("name") + "ûʲô��Ȥ����");
		return 0;
	}
	if (query("food") >= (max_food_capacity() - obj->query("food_supply"))){
		command("say �Ͻл����ڱ��úܡ�");
		return 0;
	}
	command("say ����������������ԵĽл���ѽ��");
	command("eat ji");
	command("say �벻����СС��ͣ���˼ȴ��ϸ���͸�������ض�һ����");
	call_out("dest", 1, obj);

	if (!me->query("gb/bags")){
		command("say �㻹���������ʲô��");
		return 1;
	}
	if( ob_yzz = present("yuzhu bang", ob) ){
		ob_yzz->move(me);
		command("say �����������Ҷ����ˣ����͸�����������ɡ�");
		return 1;
	}
	else{
		if( (time()-me->query("gb/jitime")) >= 100 ) {
			me->add("combat_exp",random(200));
			me->add("potential",random(100));
			if(me->query("potential")>me->query("max_pot"))
				me->set("potential",me->query("max_pot"));
			me->set("gb/jitime",time());
		}
		if ( me->query("combat_exp") <= 2000000 ){
			command("say �����ڹ���̫�������Ժ��������������Ұɡ�");
			return 1;
		}

       if ( ! ob_yywzk =(present("yuanyang wuzhenkuai", me))){
           if ( !random(10)
		&& me->query_skill("xianglong-zhang", 1) >= 200
		&& !me->query("xlz/hang")
		&& !me->query_temp("xlz/hang"))
			call_out("kanglong", 10, me, ob);
       }
       else{
           if ( !random(3)
           && me->query_skill("xianglong-zhang", 1) >= 200
           && !me->query("xlz/hang")
           && !me->query_temp("xlz/hang"))
                   call_out("kanglong", 10, me, ob);
           message_vision(HIY"$NͻȻ������������һ����������ͷһ��������$n��Ȼ���ڿ���$N��"HIW"ԧ"HIM"��"HIY"��"HIG"��"HIC"��"HIY"��������\n"NOR, me, this_object());
           command("xixi "+me->query("id"));
           destruct(ob_yywzk);
       }
		return 1;
	}
	return 1;
}
