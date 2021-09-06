// /d/mr/npc/murong-fu.c  Ľ�ݸ�
// by leontt /12/05/2000
// by tiantian@sj 6/3/2000 fix mr job bug
// Modify By River@SJ ���� job����������drugȫ��cut 12/08/Y2k
// cut gold by augx@sj 9/27/2001
// Modify By tangfeng@SJ 8/15/2004
// ���Ӹ�������ƪ��tlbb����
// By Spiderii@ty����bishen quest

inherit NPC;
#include <job_mul.h>
#include <ansi.h>
#include <combat.h>
#include "skill.h"
#include "murong-fu.h";

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

int ask_fuming(string arg);
mixed ask_bo();
string ask_fenglu();
mixed ask_sword2();
string ask_skill();
string ask_wang();
string ask_learn();
string ask_ge();
string ask_sword();
string ask_book();
string ask_book2();
string ask_times();
int ask_fangqi();
string ask_fuxing();
string ask_yuxi();
int ask_bishen();

string* npc_where = ({"/d/mr/mtl/qianyuan","/d/mr/mtl/xiaojing7","/d/mr/mtl/liulin3","/d/mr/mtl/hc2","/d/mr/mtl/keting","/d/mr/mtl/cl","/d/mr/mtl/hhyuan",});                    
                     
void create()
{
	object weapon;
	set_name("Ľ�ݸ�",({"murong fu","murong","fu"}));
	set("title","����Ľ�ݹ���");
	set("nick","�Ա�֮�� ��ʩ����");
	set("long",
		"���������ºų��Ա�֮������ʩ����Ĺ���Ľ�ݸ���\n"
		"�����ϴ��Ų���һ����Ц�ݡ�\n");
	set("age", 27);
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("no_get", "Ľ�ݸ�����������\n");

	set("max_qi",4500);
	set("max_jing", 3000);
	set("eff_jingli", 4000);
	set("neili",5500);
	set("max_neili", 3500);
	set("jiali", 1);
	set("combat_exp", 2500000);
	set("dan", 10);
	set("shen", -1000);
	set("no_bark",1);
	set("chat_chance_combat", 25);
	set("chat_msg_combat", ({
		(: exert_function, "shenyuan" :),
		(: perform_action, "strike.riyue" :),
		(: perform_action, "finger.ci" :),
		(: perform_action, "sword.lianhuan" :),
	}));
	set_skill("strike",170);
	set_skill("finger",170);
	set_skill("dodge",180);
	set_skill("force", 170);
	set_skill("canhe-zhi", 160);
	set_skill("murong-jianfa",170);
	set_skill("shenyuan-gong", 180);
	set_skill("yanling-shenfa", 160);
	set_skill("xingyi-zhang",170);
	set_skill("douzhuan-xingyi", 180);
	set_skill("parry", 180);
	set_skill("sword", 270);
	set_skill("literate", 170);
	set_skill("murong-daofa", 160);
	set_skill("blade",160);
	set_skill("xingyi-jianzhen",170);

	map_skill("blade", "murong-daofa");
	map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
	map_skill("parry", "murong-jianfa");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");

	create_family("����Ľ��", 2, "����");

	set("inquiry", ([
		"name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݸ���\n",
		"here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
		"rumors" : "�Ҹ�ͻȾ�񼲣����������˼����һ�涼û���������¶������Σ�\n",
		"����" : "�ҵĹ���ס����٢��ɽׯ���������������µ������񶴡�\n",
		"����" : "��˵�Ŀ������ֵ��������Ҳ���ʶ......\n",
		"Ҷ����" : "�Ҳ���ʶ......���Ҵ������ˡ�\n",
		"��ʩˮ��" : (: ask_ge :),
		"Ľ�ݲ�" : (: ask_bo :),
		"����" : (: ask_book :),
	//	"ٺ»" : (: ask_fenglu :),
		"������" : (: ask_wang :),
		"����" : (: ask_sword2 :),
		"����" : (: ask_sword :),
		"����" : (: ask_times :),
		"��ת����"  : (: ask_skill :),
		"ͼ��" : (: ask_book2 :),
		"��ѧ" : (: ask_learn :),
		"����" : (: ask_fuming :),
		"����" : (: ask_fangqi :),
		"��������" : (: ask_fuxing :),//tlbb quest
		"�����" : (: ask_fuxing :),
		"����" : (: ask_fuxing :),	
		"���������" : (: ask_yuxi :),
		"����" : (: ask_yuxi :),		
		"����" : (: ask_yuxi :),	
              "�Ա�֮����ʩ����" : (: ask_bishen :),
	
	]));
	set("dan_count", 2);
	set("book_count",1);
	set("book2_count" ,1);
	set("dan1_count", 2);
	setup();
	if (clonep()) {
		weapon = unew(BINGQI_D("sword/biyu-jian"));
		if (!weapon)
			weapon = new(BINGQI_D("changjian"));
		weapon->move(this_object());
		weapon->wield();
		carry_object(__DIR__"obj/cloth3")->wear();
		add_money("gold", 2);
	}
}

void init()
{
	object ob;
	::init();
	ob = this_player();
	if (interactive(ob = this_player()) 
		&&ob->query(QUESTDIR5+"start")
		&&!ob->query(QUESTDIR5+"over")
		&&ob->query_temp(QUESTDIR5+"dagouzhen")
		&&ob->query_temp(QUESTDIR5+"zhenfa")
		&&ob->query_temp(QUESTDIR5+"shaolinzhen")) {
			ob->start_busy(2);
			remove_call_out("greeting");
			call_out("greeting", 2, ob);
		}
        add_action("do_lingwu","taojiao");
	add_action("do_jiaoliang", "jiaoliang");
}
void greeting(object me)
{
	int i,p;
	if(!me) return;
	if (!me->query(QUESTDIR5+"start") 
		|| me->query(QUESTDIR5+"over")
		|| !me->query_temp(QUESTDIR5+"dagouzhen")
		|| !me->query_temp(QUESTDIR5+"zhenfa")
		|| !me->query_temp(QUESTDIR5+"shaolinzhen"))
		return;
	if(environment(me)!=environment(this_object())) 
	{
		message_vision(HIC"\n$n�ɻ���ʵ���$N�����أ�\n"NOR,me,this_object()); 
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		return;
	}
	command("whisper "+me->query("id")+" û�뵽"+ RANK_D->query_respect(me) +"��Ȼ�����ʵ�����������֣��������ַ�ħ���ؤ�����");
	command("whisper "+me->query("id")+" ��û���뵽"+ RANK_D->query_respect(me) +"��Ȼ�ܹ�����������ɮ����������֣�\n");
	command("chat* admire "+me->query("id"));
	command("pat "+me->query("id"));
	command("whisper "+me->query("id")+" ��"+ RANK_D->query_respect(me) +"�İ��������������Ҵ����ָ�տɴ���");
	command("haha "+me->query("id"));
	command("whisper "+me->query("id")+" "+ RANK_D->query_respect(me) +"�������˸����࣬��Ǵ󱦣����˽��з��͡�");

	command("addoil "+me->query("id"));
	command("crazy");

	me->set(QUESTDIR5+"over",1);
	me->delete_temp("quest/�����˲�");
	me->delete_temp("quest/busy");//�����ͻ��־ȡ��
	//����
        p=10+random(100);
	me->add("max_neili",p);
        me->add("combat_exp",me->query_skill("force")*2+500);
        i=100+random(100);
	me->add("mana",i);
        tell_object(me,HIY"\n����"+NATURE_D->game_time()+"����Ľ�ݸ��������ؤ�ʵ�ָ������µļƻ������"+p+"�����������"+((int)me->query_skill("force")*2+500)+"�㾭�齱����"+i+"��������\n"NOR);   
        log_file("quest/TLBB", sprintf("%s(%s) ��������ƪ��ɡ�������%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), p,(me->query_skill("force")*2+500),i ) );
}
void attempt_apprentice(object ob)
{
	if (ob->query_skill("parry", 1) < 120) {
		command("say �ҹ���Ľ���Ա�֮������ʩ������м�Ҫ�����ߡ�");
		command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
		return;
	}

	if (ob->query_skill("shenyuan-gong", 1) < 100) {
		command("say �ҹ���Ľ���Ա�֮������ʩ������ڹ��ķ�Ҫ�����ߡ�");
		command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
		return;
	}

	command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("say �������ϣ����ҹ���Ľ���ֵ�һ���ģ�Ϊ�����Ҵ������һ��������");
	command("chat* ����˵��������������һ���ģ������˸�ָ�տɴ�����");
	command("chat* haha");
	command("recruit " + ob->query("id"));
	ob->set("title","����Ľ�ݵ���������");
}
string ask_fuxing()
{
	object ob=this_player();
	object *obj;
	int x;

	mapping fam = ob->query("family");
	if ( !fam )
		return "��λ"+ RANK_D->query_respect(ob) +"�������ɣ��˻��Ӻ�˵��";
	if( !ob->query(QUESTDIR3+"bad"))
		return "����"+ RANK_D->query_respect(ob) +"����ûʲô�������˻��Ӻ�˵��"; 		

	if( ob->query(QUESTDIR5+"over"))
	{
		command("haha");
		command("whisper "+ob->query("id")+" ��"+ RANK_D->query_respect(ob) +"�İ��������������Ҵ����ָ�տɴ���");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}
	if( ob->query(QUESTDIR5+"start"))
	{
		command("nod " + ob->query("id"));
		command("whisper "+ob->query("id")+" Ψ��֮�ߣ��ȴ����������ˡ����ȵ��������Ǹ����ᡣ");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}
	if( ob->query_temp(QUESTDIR5+"yuxi") && !ob->query(QUESTDIR5+"start"))
	{
		command("addoil " + ob->query("id"));
		command("whisper " + ob->query("id")+" "+ RANK_D->query_respect(ob) +"�����Ǹ��߾��콫�����һأ�");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}
	if( ob->query_temp(QUESTDIR5+"give_shouji") && !ob->query(QUESTDIR5+"start"))
	{
		command("addoil " + ob->query("id"));
		command("whisper " + ob->query("id")+" "+ RANK_D->query_respect(ob) +"��ȷʵ����");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}		
    
	command("addoil "+ob->query("id"));
	command("say "+ RANK_D->query_respect(ob) +"���Ұ�����ϳ���ԭ���Ѿ����Ҵ�æ�ˣ�");
	//����ʱ��;���������
	//ʱ��һ�죬����500K
	if(ob->query(QUESTDIR+"time")&&time()-ob->query(QUESTDIR+"time")<86400)
		return "������"+ RANK_D->query_respect(ob) +"�����æ�ˣ�������Ϣȥ�ɣ�";
	if(ob->query(QUESTDIR+"combat_exp")&&ob->query("combat_exp")-ob->query(QUESTDIR+"combat_exp")<500000)
		return "��"+ RANK_D->query_respect(ob) +"Ŀǰ�ľ������Ŀǰ�������Ҳ�ﲻ��ʲôæ������ץ�������ɣ�";
	//ֻ��һ������
	obj = users();
	x = sizeof(obj);
	while(x--) {
		if ( obj[x]->query_temp(QUESTDIR5+"askfu") && obj[x]!=ob) 
		{
			command("sigh "+ob->query("id"));
			return "ֻ�ǹ���������飬�Ѿ���"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"������.........";
		}
	}
	//�趨��־
	ob->set(QUESTDIR+"time",time());
	ob->set(QUESTDIR+"combat_exp",ob->query("combat_exp"));  

	command("whisper " + ob->query("id")+" ����ֻ����ν�������£�̸�����ף�����......");
	command("look " + ob->query("id"));
	command("whisper " + ob->query("id")+" ��������������ν�����С�����һ�֮˵�����������ɡ��䵱����ؤ�");
	command("whisper " + ob->query("id")+" �������֡��䵱�˳�����̩ɽ�����������ػ�֮��������������ɮ���������˳Ʋ����Ϲ��");
	command("whisper " + ob->query("id")+" ��ؤ�������µ�һ����ǰ�ΰ������壬������������������ؤ���ߣ���������һ���ĸ��֡�");
	command("consider");
	command("whisper " + ob->query("id")+" �����������޼��ƽ��������̣����������ԭ����֮�ƣ������䵱��ϵ���ܣ�Ӱ��������Ӿ硣");
	command("whisper " + ob->query("id")+" ���ϴ������ٸ������������֣�����������Ϊ�����һ���֣�Ю����֮������Լ��Ϊ��������֮��");
	command("whisper " + ob->query("id")+" ��ˣ�Ҫ�������£�����ɨ���⡰����һ��һ��һ���ҡ����Ը�ؤ�����֣����Ѿ�����һ����ȫ֮�ߡ�");
	command("whisper " + ob->query("id")+" "+ RANK_D->query_respect(ob) +"��Ȼ��־�������£����ȴ������ᡢ���޼ɻ��������������һ����ͷ�������ң�������־��");
	log_file("quest/TLBB", sprintf("%s(%s)Ϊ����������Ҫ�����ˣ��ش˼�¼�����飺%d��\n", ob->name(1),ob->query("id"), ob->query("combat_exp")) );
	command("addoil " + ob->query("id"));
	ob->set_temp(QUESTDIR5+"askfu",1);
	ob->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
	if (random(2))		return "�����������Ǻã����Ǻá�";
	return "���������治��";
}
string ask_yuxi()
{
	string where;
	object room,mrdizi,ob=this_player();
	object *obj;
	int x;

	mapping fam = ob->query("family");
	if ( !fam )
		return "��λ"+ RANK_D->query_respect(ob) +"�������ɣ��˻��Ӻ�˵��";
	if( !ob->query(QUESTDIR3+"bad"))
		return "����"+ RANK_D->query_respect(ob) +"����ûʲô�������˻��Ӻ�˵��"; 		

	if( ob->query(QUESTDIR5+"over"))
	{
		command("haha");
		command("whisper "+ob->query("id")+" ��"+ RANK_D->query_respect(ob) +"�İ��������������Ҵ����ָ�տɴ���");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}
	if( ob->query(QUESTDIR5+"start"))
	{
		command("nod " + ob->query("id"));
		command("whisper "+ob->query("id")+" Ψ��֮�ߣ��ȴ����������ˡ����ȵ��������Ǹ����ᡣ");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}

	if( ob->query_temp(QUESTDIR5+"yuxi") && !ob->query(QUESTDIR5+"start"))
	{
		command("? " + ob->query("id"));
		command("whisper " + ob->query("id")+" "+ RANK_D->query_respect(ob) +"�����Ǹ��߾��콫�����һأ�");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}
	if(!ob->query_temp(QUESTDIR5+"give_shouji") && !ob->query(QUESTDIR5+"start"))
	{
		command("? " + ob->query("id"));
		command("whisper " + ob->query("id")+" "+ RANK_D->query_respect(ob) +"��������֪������������飿");
		if (random(2))return "�����������Ǻã����Ǻá�";
		return "���������治��";
	}

	command("nod "+ob->query("id"));
	command("whisper " + ob->query("id")+" ��Ȼ��ˣ��Ҿ�̹���Կ�������ʵ���Ǵ����Ľ���ϻ��ᣬ�˸�����Ĵ�ҵ�Ǵӹż����Ĵ�ҵ��");
	command("whisper " + ob->query("id")+" ��Ȼ������֣������ɾϹ����ᣬ�����Ը���Ϊ���Ѿ����������˵�Ŭ����\n");
	command("shrug "+ob->query("id"));
    command("whisper " + ob->query("id")+" ǰһ��ʱ�䣬��Ľ���������ӱ�����Ľ�ݣ����ɶ���Ǿ�Ȼ͵�ߴ����������");
	//ֻ��һ������
	obj = users();
	x = sizeof(obj);
	while(x--) {
		if ( obj[x]->query_temp(QUESTDIR5+"yuxi") && obj[x]!=ob) 
		{
			command("sigh "+ob->query("id"));
			return "���ã��Ѿ���"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"������.........";
		}
	}
	ob->set(QUESTDIR+"time",time());
	ob->set(QUESTDIR+"combat_exp",ob->query("combat_exp"));  

	where=npc_where[random(sizeof(npc_where))];  
	if(!room=find_object(where))
		room=load_object(where);
	if(!room) room=load_object("/d/mr/mtl/midao");
	mrdizi=new(__DIR__"mrdizi");
	mrdizi->set("party","mr"); 
	mrdizi->set("fight_id",ob->query("id")); 
	if(random(2)) mrdizi->move(room);
	mrdizi=new(__DIR__"mrdizi");
	mrdizi->set("party","mr"); 
	mrdizi->set("fight_id",ob->query("id")); 
	mrdizi->move(room);  
	mrdizi=new(__DIR__"mrdizi");
	mrdizi->set("party","mr"); 
	mrdizi->set("fight_id",ob->query("id")); 
	mrdizi->set("yuxi_have",1);//�������ĵ���
	mrdizi->move(room);
	ob->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
	tell_room(environment(mrdizi), HIB"\n"+mrdizi->name()+"�Ҵҵ�����"+room->query("short")+"����ɫ���ǻ��š�\n"NOR);
	command("whisper " + ob->query("id")+" ���Ѿ��������ݲ������޵������ղ�̽�ӻر�����ͽ����������ɽׯ"+room->query("short")+"���ֹ���");
	log_file("quest/TLBB", sprintf("%s(%s)Ϊ����������ҪѰ���������ش˼�¼�����飺%d��\n", ob->name(1),ob->query("id"), ob->query("combat_exp")) );
	command("addoil "+ob->query("id"));
	if(wizardp(ob)) tell_object(ob,"\n"+where+"\n");
	ob->set_temp(QUESTDIR5+"yuxi",1);
	if (random(2))		return "�����������Ǻã����Ǻá�";
	return "���������治��";
}
string ask_fenglu()
{
	object ob=this_player();
	mapping fam = ob->query("family");
	int gold = 0, fenglu;

	if ( !fam || fam["family_name"] != "����Ľ��")
		return "��λ"+ RANK_D->query_respect(ob) +"������Ľ�ݵ��ӣ��˻��Ӻ�˵��";
        switch ( fam["generation"] ) {
		case 2:
			gold += 500;
		case 3:
			gold += 800;
			break;
		default:
			return "��λ"+ RANK_D->query_respect(ob) +"���ҹ���Ľ�ݵ����̫�ͣ����ڻ�û���ʸ���ȡٺ»��";
	}
	fenglu = ob->query("age") * 12 + ob->query("month");
	if (ob->query("fenglu") >= fenglu)
		return "��λ"+RANK_D->query_respect(ob) +"�����Ѿ����ٺ»�ˣ����ǵ��¸��������ɡ�";
	gold *= ob->query_skill("shenyuan-gong",1);
           if (ob->query_skill("shenyuan-gong", 1) < 216)  return "�������û��ٺ»��";
	ob->set("fenglu", fenglu);
	command ("addoil " + ob->query("id"));
	ob->add("balance", gold);
	return "�㱾�µ�ٺ»"+MONEY_D->money_str(gold)+"�Ѿ�����Ǯׯ�ˣ���Ը��λ"+ RANK_D->query_respect(ob) +"��Ҫʹ��ʧ�����úøɰɣ�";
}

void reset()
{
	object ob;

	if (clonep() && (ob = unew(BINGQI_D("sword/biyu-jian")))) {
		ob->move(this_object());
		command("wield biyu jian");
	}
}

mixed ask_sword2()
{
	object me=this_player(), weapon;

	if ( me->query("family/family_name") != "����Ľ��")
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

	if ( me->query("family/generation") > 3 )
		return "�����Ǳ��ɱ����֪����λ" + RANK_D->query_respect(me) + "����������";

	weapon = present("biyu jian", this_object());
	if (!objectp(weapon))
		return "�����Ѿ�����������, ���ڲ��������";
	command("unwield biyu jian");
	command("give biyu jian to " + me->query("id"));
	return 1;
}

string ask_wang()
{
	mapping fam;

	if (!fam = this_player()->query("family") || fam["family_name"] !="����Ľ��")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	return "�������ұ��ã�һֱ������ܵĺ��ϣ����Ҷ��ܳ�ʱ��û�м������ˡ�";
}

string ask_skill()
{
	mapping fam;

	if (!(fam = this_player()->query("family"))|| fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	return "��ת��������Ľ�ݼҵľ�ѧ������ע���мܺ�����";
}

string ask_ge()
{
	mapping fam;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	return "��ʩˮ������Ľ���ղ������ؼ�֮���ڣ����ҵ��顭��";
}

string ask_sword()
{
	mapping fam;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	return "�����ǼҸ�����������ð�������������úñ��ܣ�";
}

string ask_book()
{
	object me = this_player();
	object ob;

	if (me->query("family/family_name") != "����Ľ��")
		return RANK_D->query_respect(me) +
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (me->query_skill("parry",1) < 121)
		return RANK_D->query_respect(me) + "��������������̸������";
	if (present("douzhuan xingyi", me))
		return RANK_D->query_respect(me) +
		"�������ϲ����ж�ת���Ƶ��伮������ô����Ҫ�ˣ� ����̰�����ᣡ";

	ob = unew("/d/mr/obj/shu1");
	if(!clonep(ob))
		return "��ת�����伮�Ѿ�������Ҫ���ˡ�";

	ob->move(me);

	message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n", me);
	return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";
}

string ask_book2()
{
	object me = this_player();
	object ob;

	if (me->query("family/family_name") != "����Ľ��")
		return RANK_D->query_respect(me) +
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (me->query_skill("parry",1) < 121)
		return RANK_D->query_respect(this_player()) + "��������������̸������";

	if (me->query_skill("douzhuan-xingyi",1)<50)
		return RANK_D->query_respect(me) +
		"��������������̸����ȡͼ�⣿";
	if (present("douzhuan xingyi", me))
		return RANK_D->query_respect(this_player()) +
		"���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����ᣡ";

	ob = unew("/d/mr/obj/shu2");
	if (!clonep(ob))
		return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

	ob->move(this_player());
	message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n", me);
	return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";
}

mixed ask_bo()
{
	object me = this_player();
	object ob = this_object();

	if (me->query_temp("marks/ʧ��")) {
		message_vision(
			"$N���з�����������ֱ��$n��һ��һ�ֵ�˵�����Ѿ��������ˣ�����ô������ȥ���������أ�\n",
			ob, me
		);
		return 1;
	}
	if (me->query("family/family_name") != "����Ľ��")
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";

	if (me->query("family/generation") != 3)
		return RANK_D->query_respect(me) + "Ϊ�ο������Ц��";

	if (me->query_temp("marks/bai_bo"))
		return "���Ѿ�����ȥ���Ҹ�������������ѧ�ˣ�";

	message_vision(
		"$N���з�����������ֱ��$n��һ��һ�ֵ�˵�����Ҹ����������֣���������Ի���\n"
		"�����书δ�ɣ���ò�Ҫȥ��ȡ���裻����������ģ��ͺ��ҽ���һ�¡�(jiaoliang)\n",
		ob, me
	);

	me->set_temp("marks/jiao", 1);
	return 1;
}

int do_jiaoliang()
{
	object me, obj, jiaxin;
	int current_qi;
	int i;

	me = this_object();
	obj = this_player();

	if (obj->query_temp("marks/jiao")) {
		message_vision("$N��$n˵���ðɣ��Ǿ���ʦ��ָ�㼸�С�\n", obj, me);
		set("max_qi", 4500);
		set("jiali", 50);
		set("neili", 6500);
		set("max_neili", 4500);
		current_qi = set("qi", 4500);

		i=10;
		obj->delete_temp("marks/jiao");
		while ((obj->query("qi")*100 / (int)obj->query("max_qi")) > 30) {
			if (!present(obj, environment()))
				return 1;
			i--;
			COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"), 1);
			if (!i || (me->query("qi")*100/current_qi) < 30) {
				message_vision(
					"$N��$n˵����������Ľ�������ֳ����ģ������д����ţ������϶���ǰȥ���֣�\n"
					"���������Ҹ���ϣ�����ܲ�������������Ľ�����ң��⸴�������\n",
					me, obj
				);
				jiaxin = new("/d/mr/obj/jiaxin");
				jiaxin->move(obj);
				obj->set_temp("marks/bai_bo", 1);
				message_vision("$N����$nһ�����\n", me, obj);
				return 1;
			}
			COMBAT_D->do_attack(me, obj, me->query_temp("weapon"), 1);
		}
		message_vision(
			"$N����$n����˵�������书δ�ɣ��ͺø���Զ���㻹�ǰ�������ȥ�ɣ�\n",
			me, obj
		);
		obj->set_temp("marks/ʧ��", 1);
	}
	return 1;
}

string ask_learn()
{
	int j=random(sizeof(my_skills));
	mapping skill = my_skills[j];
	int i;
	object me = this_player();

	i = 7+random(5);
	if (me->query("family/family_name") != "����Ľ��" && !wizardp(me)) // ������Ľ���ɵ���
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";

	if (me->query("combat_exp") > 2000000  && !wizardp(me))
		return RANK_D->query_respect(me)
		+ "���Ѿ����������˾���������ѧ��Ҫ���ҿɲ��������Ĵ���ˡ�";

	if (me->query_skill("parry", 1) < 100 ) // �мܱ�����ڵ���100��
		return RANK_D->query_respect(me) +
		"�ڱ�����ѧ�в����������磬���̸������֮��ѧ��";
	if (me->query_skill("douzhuan-xingyi", 1) < 100 )  // ��ת���Ʊ�����ڵ���100��
		return RANK_D->query_respect(me) +
		"�ڱ�����ѧ�в����������磬���̸������֮��ѧ��";
	if (me->query_condition("mr_job") )
		return RANK_D->query_respect(me) +"��û����ҽ�����������ء�";
	if (is_fighting())
		return "��ʲô�£�û����������æ������";
	if (me->query("job_name") =="Ľ��͵ѧ" && !wizardp(me))
		return RANK_D->query_respect(me) +
		"�ȵȵȰɣ�������û��ʲô����Ȥ���书��ѧ��";
	if (me->query_condition("wait_mr_job", 1) > 0
	 || me->query_condition("job_busy"))
		return RANK_D->query_respect(me) +"�ȵȵȰɣ�������û��ʲô����Ȥ���书��ѧ��";

	if(!skill["skill_id"])
		return sprintf("SKILL.H�ļ��ڵ�%d�����ܳ�����֪ͨ��ʦ�޸ġ�\n",j);
	me->set_temp("skill_target", skill["skill_name"]);  // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ���������
	me->set_temp("skill_id", skill["skill_id"]); // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ�Ӣ������
	me->set_temp("skill_type", skill["skill_type"]); // �˱�Ǳ����˴�͵ѧĿ�꼼�ܵ�Ӣ������
	me->set_temp("skill_lvl", i); // �˱�Ǳ����˴�͵ѧĿ�꼼������Ҫ�ļ���
	me->apply_condition("mr_job", 30+random(15)); // ���ô˴��������������ʱ�������;
	me->apply_condition("job_busy",10);
	command( "whisper "+me->query("id") + " �ҹ���Ľ�ݰ������������书����Ҳ����Ϊ֮��Ľ�ġ�");
	command("whisper "+ me->query("id")
	+ " �ðɣ�"+"��"+skill["skill_name"]+"��"+"��"+skill["skill_id"]+"���Ҵ����Ѿã����ǰ���ѧ�������Ҵ������͡�");

	if ( !present("murong paper", me))
		new("/d/mr/obj/paper")->move(me);

	if (random(2))
		return "�����������Ǻã����Ǻá�";
	return "���������治��";
}

int ask_fuming(string arg)
{
	object me, ob;
	int bouns,My_exp,Target_exp,pot;
	float rate;

	me = this_player();
	ob = this_object();

	if( !arg)
	{
		command("say ��Ҫչʾʲô��");
		return 1;
	}

	if( !me->query_condition("mr_job"))
	{
		command("say ������û������ɣ�");
		return 1;
	}

	if( me->is_busy())
	{
		command("say ����æ���أ���ʲô���������˵��");
		return 1;
	}

	if( me->is_fighting())
	{
		command("say ��������أ���ʲô���������˵��");
		return 1;
	}

	if(!me->query_temp("job_done"))
	{
		command("say ��ѧ��ʲô�����ˣ��������һ�����");
		return 1;
	}

	if( this_object()->is_fighting())
	{
		command("say ��ʲô�£�û����������æ������");
		return 1;
	}
	me->set("job_name", "Ľ��͵ѧ");
/*
	Target_exp = me->query_temp("master_exp");
	My_exp= me->query("combat_exp");

	bouns = me->query_temp("skill_lvl")*5/2;
	bouns +=  me->query_skill("douzhuan-xingyi",1) * 5 / 3;

	rate = to_float(Target_exp)/to_float(My_exp);
	if (rate > 2) rate = 2;
	if (rate < 0.6) rate = 0.6;
	bouns *= rate;
             
              if (bouns > 300) bouns = 250 + random(50);		
	bouns = me->add_exp_combat(bouns,this_object(),"Ľ��");
	pot = bouns/5+random(bouns/10);        
	if (me->add("potential", pot) > me->query("max_pot"))
		me->set("potential", me->query("max_pot"));
	write(GRN"������"+CHINESE_D->chinese_number(bouns)+"�㾭���"+CHINESE_D->chinese_number(pot)+"��Ǳ�ܵĽ�����\n"NOR);
	write(GRN"���Ѿ�ΪĽ����������"+me->query("job_time/Ľ��")+"������!\n"NOR);

	log_file("job/touxue",sprintf("%8s%-10s͵ѧ %s, ���飺%3d��Ǳ�ܣ�%2d����%3d��Ŀǰ���飺%d��\n",
		me->name(1), "("+geteuid(me)+")", me->query_temp("skill_target"),
		bouns,pot,me->query("job_time/Ľ��"),me->query("combat_exp")), me);
*/
          
	message_vision(CYN"Ľ�ݸ���ϸ�о���$N����ֽ���ϵ��书��Ҫ���鲻�Խ���˵������һ��"+me->query_temp("skill_target")+"��\n"NOR, me);
              TASKREWARD_D->get_reward(me,"Ľ��",0,0,0,16+ random(5),0,0,0,this_object());
	message_vision(CYN"Ľ�ݸ�������$N��ͷ����$P˵�����������ˣ���ȥ��Ϣ�ɡ�\n"NOR, me);


	me->improve_skill("douzhuan-xingyi", me->query_int()*2);

	me->delete_temp("skill_target");
	me->delete_temp("skill_id");
	me->delete_temp("skill_type");
	me->delete_temp("skill_lvl");
	me->delete_temp("job_done");

	me->clear_condition("mr_job");
	me->apply_condition("wait_mr_job", random(10)+5);

	if(present("paper", me)){
		destruct(present("paper",me));
	}
	return 1;
}

int ask_fangqi()
{
	object me=this_player(),obj;

	if( !me->query_condition("mr_job")){
		command("say ������û������ɣ�");
		return 1;
	}

	command( "say Ҳ�ã���ô������ȥ��Ϣһ��ɡ�" );
	command( "disapp");
	command( "sigh "+me->query("id"));
	obj=me->query_temp("dizi");
	if( objectp(obj) )
		destruct(obj);
	me->delete_temp("skill_target");
	me->delete_temp("skill_id");
	me->delete_temp("skill_type");
	me->delete_temp("skill_lvl");
	me->delete_temp("job_done");

	me->clear_condition("mr_job");
	me->apply_condition("wait_mr_job", random(2)+2);
	me->add("combat_exp",-(20+random(30)));
	return 1;
}

string ask_times()
{
	object ob;
	ob = this_player();
	if(!ob->query("job_time/Ľ��"))
		return "���ź���"+ob->name()+"�������û��ΪĽ���������ף�";
	return ""+ob->name()+"�����Ѿ������"+CHINESE_D->chinese_number((int)ob->query("job_time/Ľ��"))+"��Ľ��͵ѧ����";
}

int accept_object(object who, object ob)
{
   if(userp(ob)) return 0;        
   if(ob->query("id") == "yu xi")
   {
      if(who->query_temp(QUESTDIR5+"yuxi")
		  &&!who->query(QUESTDIR5+"start")) 
	  {
      	if( ob->query("owner")==who->query("id"))
        {
           command("smile "+who->query("id"));
  	       command("whisper "+who->query("id")+" ��������������ģ������и��������ܿ��Ը����㡣");
  	       command("whisper "+who->query("id")+" ��ʮ��ǰ������Ҷ��ׯҶ����������ʧ�٣�����󽭺��ϳ�����ν�Ĵ���ˣ�����һ���ͽ�Ҷ���");
		   command("smile "+who->query("id"));
  	       command("whisper "+who->query("id")+" û�����뵽��Ҷ������ǵ���Ҷ���������һ��������׾��ǵ���������������ȣ�");
		   command("smoke");
  	       command("whisper "+who->query("id")+" ��ʮ��ǰ�������������������ҹ��Ҷ��ׯ������Ҷ����������Ҷ�������Ϊ������һ�ӡ�");
  	       command("whisper "+who->query("id")+" �����������Ļ��ᡣ������Ӿ���������ʮ��������������ƨ���ϵ�̥�ǿ���֤��һ�У���");
		   command("claw");
  	       command("whisper "+who->query("id")+" ���һ������������ɨ�أ�֮���ؤ��������������֮������ؤ�֮�����ֱ������ҵ����£�");
           command("crazy");
           command("addoil "+who->query("id"));
           who->set(QUESTDIR5+"start",1);
		   log_file("quest/TLBB", sprintf("%s(%s)Ϊ���������ҵ����������飺%d��\n", who->name(1),who->query("id"), who->query("combat_exp")) );
        }
        else
        {
           command("? "+who->query("id"));
  	       command("whisper "+who->query("id")+" �ⲻ����Ҫ�ҵ���������������������ģ�");
  	       command("heng "+who->query("id"));
		   command("whisper "+who->query("id")+" ��Ȼ�������һ�������Ū��.........");
		   log_file("quest/TLBB", sprintf("%s(%s)�ҵ��������Ǳ��˵ģ�ʧ�ܡ����飺%d��\n", who->name(1),who->query("id"), who->query("combat_exp")) );
           who->set(QUESTDIR+"time",time());
           who->set(QUESTDIR+"combat_exp",who->query("combat_exp"));
           who->delete_temp("quest/�����˲�/��������ƪ");
        }
	  }
	  else command("thank "+who->query("id"));
	  call_out("destroying", 1, ob);
	  return 1;
   }
   if(ob->query("id") == "shouji" 
	   && ob->query("kill_by")
	   && ob->query("kill_by")==who
	   && (ob->query("victim_id")=="zhang sanfeng"
	       ||ob->query("victim_id")=="zhang wuji"
		   ||ob->query("victim_id")=="kurong zhanglao"))
   {

      if(who->query_temp(QUESTDIR5+"askfu")
		  &&!who->query_temp(QUESTDIR5+"give_shouji")) 
	  {
		  command("smile "+who->query("id"));	  
		  if(ob->query("victim_id")=="zhang sanfeng")
			  command("whisper "+who->query("id")+" �����䵱�Ǹ�����ëû�뵽Ҳ�н��죬�����и��������ܿ��Ը����㡣");
		  if(ob->query("victim_id")=="zhang wuji")
			  command("whisper "+who->query("id")+" ���������Ǹ�С�һ�û�뵽Ҳ�н��죬�����и��������ܿ��Ը����㡣");
		  if(ob->query("victim_id")=="kurong zhanglao")
			  command("whisper "+who->query("id")+" ���������Ǹ���ͺ��û�뵽Ҳ�н��죬�����и��������ܿ��Ը����㡣");
		  command("addoil "+who->query("id"));
		  who->set_temp(QUESTDIR5+"give_shouji",1);
		  log_file("quest/TLBB", sprintf("%s(%s)Ϊ��������ɱ��һ�������ˡ����飺%d��\n", who->name(1),who->query("id"), who->query("combat_exp")) );
	  }
	  else
	  {
		  command("nod "+who->query("id"));
		  command("admire "+who->query("id"));
	  }
	  call_out("destroying", 1, ob);
	  return 1;
   }
   return 0;
}
int ask_bishen()
{
	object ob=this_player();
       mapping fam;
	int i, time;
        i = ob->query("combat_exp") - 500000;
        i /= 500000;

	time = time() - ob->query("quest/bishen/time");


      if (!(fam = this_player()->query("family")) || fam["family_name"] !="����Ľ��"){
		command("? " + ob->query("id"));
             command("say ���뱾��������������֪Ϊ���д�һ�ʣ�");
             return 0;
        }
	if (ob->query("quest/bishen/pass")) {
		command("? " + ob->query("id"));
		command("say �㲻���Ѿ��������еİ�������");
		return 1;
	}
	if (ob->query("quest/bishen/fail") >=3 && ob->query("registered") < 3){
		command("hmm");
		command("say ������������,�������������ˣ�");
		return 1;
	}
	if ( ob->query("quest/bishen/time") && time < 86400 ) {
		command("shake");
		command("say �����ʱ��δ��,���Ժ�������");
		return 1;
	}
	if ( ob->query("quest/hubo/fail") >= i ){
		command("shake");
		command("say �����ʱ��δ��,���Ժ�������");
		return 1;
	}
        if ( ob->query("combat_exp") < 1000000) {
		command("shake "+ ob->query("id"));
		command("say ��λ"+RANK_D->query_respect(ob)+"����书���ڸ���,���ڻ����Ǹ������ʱ��");
		return 1;
	}
	if (random(ob->query("kar")) < 26 && ob->query("int") < 25){
	       command("look " + ob->query("id"));
		command("poor");
		command("say �����㻹��δ���������а������ڵ�ʱ��!");
		ob->add("quest/bishen/fail", 1);
		ob->set("quest/bishen/time", time());
		log_file("quest/bishen",
			sprintf("%-18s���Ľ�ݸ�������ת���Ƶľ�������ʧ�ܣ�ʧ��%s�Ρ�\n",
				ob->name(1)+"("+capitalize(getuid(ob))+")",
				chinese_number(ob->query("quest/bishen/fail")) 
			), ob
		);
		return 1;
	}
	command("look " + ob->query("id"));
	command("nod " + ob->query("id"));
	command("say �ð�,�Ҿͽ����еİ��������ɡ�");
       command("chat* ������Ц�����ҹ���Ľ������һ������ת���ƾ�������,�γ����ҵ���ɣ�");
       command("chat* yeah");
	log_file("quest/bishen",
		sprintf("%-18sʧ��%s�κ󣬳ɹ���Ľ�ݸ�������ת���ƾ������ڣ�����%d����%d��\n",
			ob->name(1)+"("+capitalize(getuid(ob))+")",
			chinese_number(ob->query("quest/bishen/fail")), 
			ob->query("kar"), 
			ob->query_int(1)
		), ob
	);
	ob->set("quest/bishen/pass", 1);
	ob->set("quest/bishen/exp", ob->query("combat_exp"));
	return 1;
}



void destroying(object ob)
{     
	destruct(ob);
	return;
}     
