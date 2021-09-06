// laozu.c Ѫ������
// by iceland
// by emnil

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/d/suzhou/npc/lchj.h";
#define QUESTSD "quest/ѩɽ/shendao"
string ask_xuedao();
string ask_zijindao();
string ask_jiasha();
string ask_diyun();
string ask_jidao();
void create()
{
	object weapon , armor;

	set_name("Ѫ������", ({ "xuedao laozu", "laozu","xuedaolaozu" }));
	set("long",@LONG
����ĸ��ݣ��������ݣ�һ˫�۾�����׺ݵĹ�â�����˲���ֱ�ӡ����ڽ���
���Բ��̺�ɫ�����ƣ���ƾһ��Ѫ�����Ĺ��򶷰�������ԭ�����ֺ��ܡ�
LONG
	);
	set("title", HIR "������Ѫ��������" NOR);
	set("gender", "����");
	set("class", "huanxi");
	set("no_bark",1);
	set("age", 65);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 39);
	set("int", 30);
	set("con", 35);
	set("dex", 35);
	set("max_qi", 11500);
	set("max_jing", 8000);
	set("eff_jingli", 8000);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 250);
	set("combat_exp", 4200000);
	set("score", 50000);
	set("unique", 1);

	set_skill("huanxi-chan", 200);
	set_skill("literate", 250);
	set_skill("force", 380);
	set_skill("longxiang-boruo", 380);
	set_skill("dodge", 340);
	set_skill("yuxue-dunxing", 340);
	set_skill("claw", 350);
	set_skill("tianwang-zhua", 320);
	set_skill("hand", 350);
	set_skill("dashou-yin", 320);
	set_skill("blade", 350);
	set_skill("xuedao-jing", 380);
	set_skill("parry", 340 );

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "xuedao-jing");
	map_skill("claw", "tianwang-zhua");
	map_skill("blade", "xuedao-jing");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	create_family("������", 10, "����");
	set("class", "huanxi");

	set("env/jixue",10);
	set_temp("xs/shield",1);
	set_temp("xs/longxiang",1);

	set("chat_chance", 2);
	set("chat_msg", ({
	       CYN"Ѫ������̧��ͷ��������˼�����������������Բ�ˣ�����ɽɱ���˼������ˡ���\n"NOR,
	       CYN"Ѫ������޺޵�˵����ʲôʱ��������ԭ�����ָ��췭�ظ�����\n"NOR,
	       CYN"Ѫ������ҧ���гݣ���¶�׹��˵�����´�����ն�ݳ�����һ�����Ҳ��������\n"NOR,
	       CYN"Ѫ���������������������ʹ��ˣ�������һ��Ҳ����������������Ϊ���⡣\n"NOR,
	       CYN"Ѫ�������������������Ѫ����ʮ���������Ŀ��Ǻö���ѽ��һ��Ҫ�غá�\n"NOR,
	}) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "blade.jixue" :),
		(: perform_action, "blade.shendao" :),
	}));

	set("inquiry", ([
		"Ѫ��":		(: ask_xuedao :),
		"xuedao":	(: ask_xuedao :),
		"�Ͻ�": 	(: ask_zijindao :),
		"zijin dao":	(: ask_zijindao :),
		"ʮ����������":	(: ask_jiasha :),
		"jiasha":	(: ask_jiasha :),
		"����":		"үү��û�գ���ȥ����ͽ�ܱ����������ʰɡ�",
		"job" :		"үү��û�գ���ȥ����ͽ�ܱ����������ʰɡ�",
		"��Ů":		"����ϲ����Ů������Ҫ����Ū������Т��үү���ٺ�...",
		"girl":		"����ϲ����Ů������Ҫ����Ū������Т��үү���ٺ�...",
		"beauty":	"����ϲ����Ů������Ҫ����Ū������Т��үү���ٺ�...",
// add quest by tangfeng
		"����" : (: ask_diyun :),
		"���վ�" : random(2)?"��˵������ī��÷���ϵ��ڹ��ķ���":"�Ҽǵ������֮�ھͿ������վ��ڹ��ķ���",
		"����ɽ" : "÷�����ϵĵ��ӡ�",
		"�Դ�ƽ" : "÷�����ϵĵ��ӡ�",
		"�ݳ���" : "÷�����ϵĵ��ӡ�",
		"÷����" : "����ī��÷���ϣ���ϧ����ԩ������",
		"�仨��ˮ":"��˵��ʲô�����棿�ߣ����˻���ͷ�������Ķ��Ѿ�����ɱ�ˣ�",
		"������":"����ƽǹ�����ɡ������Ǹ��޳ܵ�ų��",
		"���˷�":"�����ƽ����˷硱���������Ѿ��Ѿ�����ɱ�ˣ�",
		"½����":"������½�󵶡����������Ѿ�����ɱ�ˣ�",
		"ˮ�":"�����½�ˮᷡ����������Ѿ�����ɱ�ˣ�",
		"ˮ��":"��С���ĵ��Ǳ�־����ϧ�ܶ��ˣ�����Ҳ��������ѩ���ˣ�",
"����" : (: ask_jidao :),
       ]));

	setup();
	if (clonep()){
		weapon = unew(BINGQI_D("zijin-dao"));
		if(!weapon) weapon=new(BINGQI_D("xinyuedao"));
		weapon->move(this_object());
		weapon->wield();
		set_temp("apply/damage",180);

		weapon=new(BINGQI_D("xinyuedao"));
		weapon->move(this_object());
		weapon=new(BINGQI_D("xinyuedao"));
		weapon->move(this_object());

		armor=new("/d/xueshan/npc/obj/longxiang-jiasha");
		armor->move(this_object());
		armor->wear();
		set_temp("apply/armor",300);
	}
	add_money("gold",3);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "������") {
		command("say"+ RANK_D->query_respect(ob) + "���Ǳ��µ��ӣ������ﵷʲô�ң���");
		return;
	}
if( ob->query("family/master_name") == "���ַ���" || ob->query("family/master_name") == "�Ħ��" )
{
command("say "+ RANK_D->query_respect(ob) + "������ʦָ�㣬�Ҳ������㣡");
return ;
}
	if ((int)ob->query_skill("longxiang-boruo", 1) < 150) {
		command("say �Ҵ����¸����书�����ڹ��ศ��ɡ�");
		command("say"+ RANK_D->query_respect(ob) + "�ٰ�����ͨ��������������б��ŵ��ķ��ɡ�");
		return;
	}

	if( (string)ob->query("gender") == "����" ) {
		command("say"+ RANK_D->query_respect(ob)+ "�����ȱ���������������\n");
		return;
	}
	if ((int)ob->query("shen") > -100000) {
		command("hmm");
		command("say ��Ѫ����������Զ���Щ��ν�Ľ��������ĸ�����������ӣ�");
		command("say �������ڵ��������������Ϊͽ�����»ᱻ�˳�Ц��");
		return;
	}
	command("say �����Ҿ�ϲ���������������ˡ��ã�������Ϊ�ҵ��Ӱɡ�");
	command("recruit " + ob->query("id"));

	ob->set("title", HIR"������Ѫ�������״�����" NOR);
}

void reset()
{
	object me = this_object(), ob;

	if (clonep() && (ob = unew(BINGQI_D("xuedao")))) {
		ob->move(me);
		command("wield xue dao");
	}
	if (clonep() && (ob = unew(BINGQI_D("zijin-dao")))) {
		ob->move(me);
		command("wield zijin dao");
	}
	if (clonep() && (ob = unew(ARMOR_D("lx_cloth")))) {
		ob->move(me);
		command("wear shisan longxiang");
	}
}

string ask_xuedao()
{
	object me=this_player() , weapon;
	int i;

	if ((string)me->query("family/family_name") != "������")
		i = 3;
	else
		i = 1;

	if(me->query_temp("xs/xs_job") >= 1*i) {
		weapon = present("xue dao", this_object());
		if(!objectp(weapon))
			return "Ѫ�����ڲ��������";

		command("unwield xue dao");
		command("give xue dao to "+me->query("id"));
		me->delete_temp("xs/xs_job");
		return "�ã����Ѫ������ȥ�ɣ����Ŷ�ɱ����������������";
	}
	return "����Ҫ��ѵ�������Ҫ��˵���Ȼ����г���ؿ����ң�������Ҫ˵��ѽ��\n"+
		"��˵���ҿ϶������ģ���������˵���Ҳ����㣬���㲻˵��ƫҪ����ɡ�";
}

string ask_zijindao()
{
	object me=this_player() , weapon;

	if ((string)me->query("family/family_name") != "������")
		return "����������ˣ���ѵ���ô�ܸ����أ�";

	if ((int)me->query("job_time/ѩɽ") < 50 )
		return "�Ķ������ж����õ�ʵ�ʳɼ������ҿ��";

	weapon = present("zijin dao", this_object());
	if (!objectp(weapon))
		return "�Ͻ����ڲ��������";

	command("unwield zijin dao");
	command("give zijin dao to "+me->query("id"));

	return "�ã�����Ͻ�����ȥ�ɣ���ס��Ҫ������ѽ��";
}

string ask_jiasha()
{
	object me=this_player() , armor;
	int i;

	if ( me->query("family/family_name") != "������")
		i = 5;
	else
		i = 1;

	if(me->query_temp("xs/xs_job") >= i) {
		armor = present("shisan longxiang", this_object());
		if(!objectp(armor))
			return "ʮ�������������ڲ��������";

		command("remove shisan longxiang");
		command("give shisan longxiang to "+me->query("id"));
		me->delete_temp("xs/xs_job");
		return "�ã����ʮ��������������ȥ�ɣ����Ŷ�����Ҽ������ﰡ��";
	}
	return "�Ķ������ж����õ�ʵ�ʳɼ������ҿ��";
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
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
	   return "�Ǹ����ͷ��С����ôͻȻ��ô�����ˣ�";
	}
	if(!me->query(QUESTDIR1+"start" ))
	{
	   command("say");
	   return "���Ҵ�ѩ���ȥ�ˣ�������Ͷ����ˡ�";
	}
	if(!me->query_temp(QUESTDIR1+"askbaoxiang" ))
	{
	   command("say");
	   command("claw "+me->query("id"));
	   return "�ĸ����ƣ�����˭��";
	}
	if(me->query_temp(QUESTDIR1+"asklaozu"))
	{
	   command("en");
	   return "�Ǹ����ͷ��Ҳ�����Ҳ�������Ӧ�ö����ˣ�";
	}
	command("smash");
	message_vision(HIY"$N��ɫ�԰��ؿ���$n��\n", ob,me);
	command("noshame");
	me->set_temp(QUESTDIR1+"asklaozu",1);
	return "����Ȼ�������ԣ�ֻ�����ֿ�ԣ����Ҵ�ѩ���ȥ�ˣ�������Ͷ����ˡ�";
}
string ask_jidao()
{

object me,ob;
	me = this_player();
	ob = this_object();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return ""+RANK_D->query_respect(me) +"�����Լ�С��ͨ���ɣ�";
	}
if( me->query("family/master_name") != "Ѫ������" )
{
return " �����������ģ���������Ұ��ԣ�����үү�ġ��񵶴��ġ���";
}
if( me->query("quest/ѩɽ/shendao/jidao") )
{
return " ����Ҷ�ǿ�ˣ������ң��ǲ���������үү��";
}

if(!me->query("quest/���Ǿ�/�书/shenzhao"))
{
command("consider");
return " �ҷ��ֵ�����С�ӽ�Ѫ���������վ���ϵĳ����뻯��"+RANK_D->query_respect(me) +"��ѧȫ���վ�����";
}
if(me->query(QUESTSD+"shendao_fail")>=3 && me->query("registered")<3)
{
return " �ٺ٣��Ҿ�֪���������ˣ�";
}

if(me->query(QUESTSD+"time") && time()-me->query(QUESTSD+"time")<86400)
{
return " �������ʵ��������ɣ�";
}
if(me->query(QUESTSD+"combat_exp") && me->query("combat_exp")-me->query(QUESTSD+"combat_exp")<50000 && !me->query("cw_exp"))
{
return " ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɣ�";
}

me->set(QUESTSD+"time",time());
me->set(QUESTSD+"combat_exp",me->query("combat_exp"));
if(random(me->query("kar")) >= 28 && random(15) == 1 && me->query("buyvip"))
{ 
 
message_vision(HIR"$N��������ؿ���$n��\n", ob,me);
me->set_temp("quest/ѩɽ/shendao/jidao/asklaozu",1); 
command( "say �ҷ��ֵ�����С�ӽ�Ѫ���������վ����ʹ�ã���ֱ�����뻯��");
command( "say ���������Ǽ���......");
message_vision(HIR"$N˵������ͻȻ��ʶ��ʲô���ʹ˴�ס��˵�ˡ�\n", ob,me);
log_file("quest/xueshan/shendao", sprintf("%8s(%8s) ʧ��%d��ѧ��Ѫ����������|���飺%d��\n", me->name(1),me->query("id"), me->query(QUESTSD+"shendao_fail"),me->query("combat_exp")) );
return " ���У���Ȼ������ͽ�ܣ���Ҳ���ܸ����㣡";

 
}
else
{
me->add(QUESTSD+"shendao_fail",1);
 log_file("quest/xueshan/shendao", sprintf("%s(%s) Ѫ��������ʧ��%d�Ρ�|���飺%d��\n", me->name(1),me->query("id"),me->query(QUESTSD+"shendao_fail"), me->query("combat_exp")) );
command("? "+me->query("id"));
return " ��Բ�ˣ��Ǹü����ˣ���Ȼ�����������������Ѫ��������ѵ��ɡ�";

}
}
