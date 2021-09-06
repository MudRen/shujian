// /d/thd/npc/huangrong.c
// Modified by action@sj
//���Ӣ�۴���28��

#include <ansi.h>
inherit NPC;
#include "nadir.c"
#include "thdjob.h"

int ask_husband();
int ask_shouhuan();
int ask_jiuyin();
int ask_job_s();
int ask_job();
int ask_job_time();
int ask_quest();
int ask_book();
int ask_qqzhang();
int ask_qqchi();

void create()
{
	set_name("����", ({ "huang rong", "huang", "rong" }));
	set("long",
			"���������䣬����ʮ��������ͣ�����ʤѩ�������ޱȣ���ɫ���������ɱ��ӡ�\n"
			"���������磬ȫ����£�ͷ��������һ���������Ȼ���⡣һ��װ��������Ůһ�㡣\n");
	set("gender", "Ů��");
	set("rank_info/rude", "С��Ů");
	set("age", 16);
	set("attitude","peaceful");
	set("str", 16);
	set("dex", 26);
	set("con", 18);
	set("int", 30);
	set("per", 50);
	set("shen_type", 0);

	set("tu", 1);
	set("shu", 1);
	set("shouhuan",1);

	set("jiali",50);
	set_skill("force", 200);
	set_skill("huntian-qigong", 200);
	set_skill("bihai-chaosheng", 200);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("luoying-zhang", 200);
	set_skill("hand", 200);
	set_skill("lanhua-shou", 200);
	set_skill("finger", 200);
	set_skill("tanzhi-shentong", 200);
	set_skill("sword", 200);
	set_skill("yuxiao-jian", 200);
	set_skill("literate",500);
	set_skill("qimen-bagua", 500);
	set_skill("bangjue",200);
	set_skill("dagou-bang",200);
	set_skill("stick",200);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "luoying-zhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("parry", "dagou-bang");
	map_skill("sword", "yuxiao-jian");
	map_skill("stick", "dagou-bang");
	prepare_skill("hand", "lanhua-shou");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.ban" :),
		(: perform_action, "stick.yin" :),
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.chan" :),
		(: perform_action, "stick.wugou" :),
		(: exert_function, "huntian" :),
	}));

	set("combat_exp", 2500000);
	set("max_qi", 5000);
	set("max_jing", 4000);
	set("neili", 7500);
	set("max_jingli", 8500);
	set("eff_jingli", 8500);
	set("max_neili", 8500);

	set("inquiry", ([
		"name" : "���»��أ����һ�������Ů����",
		"rumors" : "�ҵ��������ﲼ��һ�������󣬱��뾫ͨ���Ե��������ͨ����",
		"here" : "��������һ����ˡ������Ǹ�С������������������ģ�������������ܲ�����ȫ�ˡ�",
		"����" : "�������Ȼ�е�ɵ�����ģ�����ȴ�����ĵġ�",
		"����" : "��������ʲô����",
		"��ҩʦ" : "�ҵ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
		"����" : "�ҵ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
		"��а" : "�ҵ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
		"�ܲ�ͨ" : (: ask_jiuyin :),
		"������" : "�ǵ��������Ե������ŵģ���ͬ�ķ����ʾس�ı仯���ÿ��سΪһ�ԣ����԰�˳���߶Ծ͹����ˡ�",
		"س" : "��Ҳ��֪������û�������ˡ�",
		"�ɷ�" : (: ask_husband :),
		"�ֻ�" : (: ask_shouhuan :),
		"���" : (: ask_husband :),
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
// here add thd-job "ask huang" by Numa 19990911
		"ʦĸ": (: ask_job_s :),
		"��Ĺ": (: ask_job :),
// ask job times by Numa 19991005
		"����": (: ask_job_time :),
// add for taohua quest
		"÷����": (: ask_quest :),
		"������": (: ask_quest :),
// for hetu/luoshu
		"���Ű���": (: ask_book :),
		"��ǧ��": (: ask_qqzhang :),
		"��ǧ��": (: ask_qqchi :),
//		"��ǧ��": (: ask_qqren :),
	]) );

//here set do job's number
	set("thd/havejob",1);

	setup();

	carry_object(__THD__"obj/gold_ribbon.c")->wear();
	carry_object("/d/city/obj/necklace.c")->wear();
	carry_object(__THD__"obj/white_cloth.c")->wear();
	carry_object(__THD__"obj/gold_belt.c")->wear();
	carry_object("/d/city/obj/goldring.c")->wear();
	carry_object("/clone/weapon/zhubang")->wield();
}

void reset()
{
	set("tu", 1);
	set("shu", 1);
	set("shouhuan",1);
}

int ask_jiuyin()
{
	object me= this_player();
	if (me->query_temp("jyquest")!=1) {
		command("say ��֪����������ô�ˡ�");
		command("consider");
		return 1;
	}

	command("say �������Ǳ��������ڵ��ϣ���֪��Ϊʲô��");
	command("say �����춼�����ͷ��������������Ҫ�Һú���Щ����������");
	command("angry");
	command("say �����ɣ��������ȥ�ɺã�");
	message_vision(HIY"���ظ�$Nһ�����С�\n"NOR,me);
	me->set_temp("jyquest",2);
	new(__THD__"obj/fanhe")->move(me);
	return 1;
}

int ask_shouhuan()
{
	object me= this_player();
	if (me->query("family/family_name")!= "�һ���") {
		command("say ���ֲ������һ������ӣ���������Ϲ����ʲô��");
		return 1;
	}
	if( present("yin shouhuan", me)) {
		command("angry");
		command("say �Ѿ���������");
	}
	if(query("shouhuan") < 1)
		return notify_fail("�ֻ��Ѿ����������ˡ�\n");

	if(me->query("job_time/�һ���") < 300) {
		command("say �㲻���æ���ҲŲ����㡣");
		return 1;
	}
	command("say �ðɣ�������ƽ�����Ҳ���æ���͸����˰ɡ�\n");
	new("/d/thd/obj/shouhuan")->move(me);
	add("shouhuan",-1);
	return 1;
}

int ask_husband()
{
	object nvxu, user;
	object ob = this_player();
	string id;
	int user_load = 0;

	if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
		nvxu = load_object("/clone/npc/huang-son-in-law");
	id = nvxu->query("winner");
	if (!id)
		id = "";
	if (id == ob->query("id")) {
		if (nvxu->query("death_count") < ob->query("death_count"))
			say("���ص���ͷ��Ū���½ǣ�ʲô��Ҳ��˵��\n");
		else
			message_vision(CYN"���غ��������ؿ���$N���۹⽿�����ޡ�\n"NOR, ob);
	}
	else {
		if (!(user = find_player(id))) {
			user = new(LOADUSER_OB, id);
			if (!user->restore()) {
				say("���ص���ͷ��Ū���½ǣ�ʲô��Ҳ��˵��\n");
				destruct(user);
				return 1;
			}
			user_load = 1;
		}
		if (nvxu->query("death_count") < user->query("death_count"))
			say("���ص���ͷ��Ū���½ǣ�ʲô��Ҳ��˵��\n");
		else
			command("say �ҵ��ɷ����" + nvxu->query("name") + "��");
		if (user_load) destruct(user);
	}
	return 1;
}

int ask_job_time()
{
	object me = this_player();
	int i;

	if (me->query("family/family_name")!= "�һ���") {
		command("say ���ֲ������һ������ӣ���������Ϲ����ʲô��");
		return 1;
	}
	if(!intp(i = me->query("job_time/�һ���")) || i<=1 ) {
		command("say ��������û�ع�Ĺ��?");
		return 1;
	}
	message_vision("���ص��˵�ͷ����$N˵��������Ϊ���һ����ɹ���Ĺ" + chinese_number(i) + "�Ρ�\n",me);
	command("addoil " + me->query("id"));
	return 1;
}

int ask_book()
{
	object me = this_player();
	object book;
	int i = random(20) + 1;

	if(me->query("potential") < i)
		return notify_fail("���Ǳ�ܲ����ˡ�\n");

	if(me->query("job_time/�һ���") < 200) {
		command("say ��û��æ�������°ɣ�");
		command("hehe");
		return 1;
	}

	if((present("he tu", me)||present("luo shu", me)) && (me->query_skill("qimen-bagua",1) < 200)) {
		command("say �Ҿ�ָ����һ�����Ű��Եļ��ɰɡ�");
		message_vision(HIW"����ָ����$Nһ���ͼ�����������֮ѧ��\n"NOR,me);
		me->improve_skill("qimen-bagua", random(me->query_int())* i);
		me->add("potential", -i);
		if(me->query("job_time/�һ���") < 0)
			me->set("job_time/�һ���",0);
		return 1;
	}

	if (me->query("family/family_name")!= "�һ���") {
		command("say ���ֲ������һ������ӣ���������Ϲ����ʲô��");
		return 1;
	}

	if ((me->query("job_time/�һ���")<200) && (me->query("thd/finish")<1)) {
		command("say ����Ҷ���Щ�£��Ҳ�Ҫ�����顣");
		command("xixi");
		return 1;
	}
	if((me->query_skill("qimen-bagua",1)<120) && (query("tu")>0)) {
		book = unew("/d/thd/obj/hetu");
		if (book) {
			command("say �ðɣ��Ȿ��ͼ����ȥ�ú��ж��ɡ�");
			book->move(me);
			add("tu",-1);
		} else {
			command("say ���Ѿ����������ˡ�");
			command("sorry");
		}
		return 1;
	}
	if( me->query_skill("qimen-bagua",1) > 100
	 && query("shu") > 0 ) {
		book = unew("/d/thd/obj/luoshu");
		if (book) {
			command("say �ðɣ��Ȿ��������ȥ�ú��ж��ɡ�");
			book->move(me);
			add("shu",-1);
		} else {
			command("say ���Ѿ����������ˡ�");
			command("sorry");
		}
		return 1;
	}
	command("say ������û�������飬��������");
	command("yawn");
	return 1;
}

int ask_quest()
{
	object me = this_player();

	if (me->query("family/family_name")!= "�һ���")	{
		command("say ���ֲ������һ������ӣ���������Ϲ����ʲô��");
		return 1;
	}
	if (me->query_temp("thd/onquest")==0)	{
		command("say ���Ǳ����ǵ�����ͽ��......�㻹���Լ�ȥ�ʵ��ɡ�");
		command("consider");
		return 1;
	}
	if (me->query_temp("thd/onquest")==2)	{
		command("say �����书��ǿ����ҪС���ˣ�");
		command("fear");
		return 1;
	}
	command("ah");
	command("say ������а�ذ�ף�����ȥ����....��Σ��ʱ���ͳ�(chou)�����ɡ�");
	message_vision(HIY"$NС������ذ�ذ�ײ���ѥ���Ρ�\n"NOR, me);
	command("say �������о��������֣��ɱ�Ū���ˡ�");
	command("blush");
	me->set_temp("thd/onquest",2);
	return 1;
}

int ask_qqzhang()
{
	      object me= this_player();
	if (me->query_temp("quest/jindaoheijian/huangrong")!=1) {
		 command("say 20�����˲���ô�ǵ��ˣ����������ʲô��");
		 command("consider");
		  return 1;
	}
	   command("say ������ǧ�ɰ��Һ;����ƭ�ĺÿడ��������ǧ�����Ʒ�͵Ϯ�ң�ʧ�����ɽ�¡�");
	   message_vision(WHT"\n������ɫ���أ��������䵱�귢�����Ʒ�ľ���!\n"NOR,me); 
	   command("sigh");
     message_vision(HIC"������ʱʡ�򣺡����ǲ��ҽ�����أ���ʹ�𹥡�ɽ�������Ż�֮����·ٻ٣�����������\n"+     
        	             "��ȴҪ���ĸ����ɽ�̿�˼�æ��������أ�ֻ����ǧ�����ڵ����ƿڴ��������������\n"+
        	             "�������������ţ��⿪����Ѩ���������������ߣ���ľ�к��������Ӵ��ڻ�����Ҷ�������\n"+
        	             "�嶥��ȥ����ʯѨ������ָ��ĵڶ�ָ�ڣ���嶥������ʮ��֮ң����������������Ƭ��֮��\n"+        	                      
        	             "�ʵǷ嶥����ǧ��Ҳ����һ�����İ�������������ͷ������ȥ�����������������ϣ���Ȼһʱ\n"+
        	             "���±㵽���վ��������������ɵó�̾һ�������غ������������������ɣ������٣�������\n"+
        	             "����٣��ò��ã����������ʵ�������ô��٣������ص������е���������Ƿ���ȥ������һ\n"+
        	             "�����ԣ�����ϲ�������������е������ǵ������ý����һ����������ֻ��֪�����û���\n"+
        	             "��������������̾����������������Ҳֻ��ð��һ���ˡ�������������ϥ������������������\n"+
        	             "��������Ƭ�̣�Ȼ��Ӻ��һ�¶�����Х��ԶԶ���˳�ȥ�������������ڵ���������ȫ������\n"+
        	             "���ڹ�������ϰ�������澭��֮�󣬹������Ǿ�����������ָ���Է嶥���������ֹ���\n"+
        	             "��Х��������������ʱ���Ӱ�ٿգ�˫�����¹������������ͣ�ڶ�����ǰ������������ؽ�\n"+
        	             "��������⬼ף��������ڴƵ��ϣ������˺��������֣������´��������������ס��Ȼ��\n"+
        	             "�Լ������۵�֮����§ס�񾱣�����һ����Х��˫�������𡣡����˶�Ȼƾ���ٿգ���˫��\n"+
        	             "һ����أ�����ƽ���쳣��������ʱ�����Լ������أ����ǵ��δ�ظ��ɵ�����֪�ǰ׵�˫\n"+
        	             "��չ������Ȼ���޼���֮�񡣡����ؾ���С�����ԣ���������������ۣ��ɵ�����ǧ�����϶�\n"+
        	             "�Ƹ���ϸ�����������񾱣�Ҫ��������ǧ�����ԡ����Ƶ������ɽ�����ǧ�����Ի��ң��ۼ�֮\n"+
        	             "�£������־����ۣ��е������ù��Ҳ�����߰ա�������Ҫ���������϶��ɻ��������\n"+
        	             "����Ц���������������������ˡ�������ܾܵ��㣬���ͳ����������������ǧ�ߣ�������\n"+
        	             "�����ɡ������ĵ񾱣�ת��ɿ�������ǧ�ɴ󼱣��е������ù�����������������Ȥ\n"+
        	             "�����������غ������������ͷ��Ҫ����������ô���⡣��֪��ǧ��ͻȻ������ǰ���ˣ���\n"+
        	             "����ɽ�壬����ر��ϱ�ȥ������֪���ǳ��·�ȥ�������ѳ���Ȧ����˽����أ����˰�����\n"+
        	             "�棬Ī˵�ǰ������ֵܣ������ǰ������ˣ�Ҳδ���ܹ���������ʱ����������ʯ���ܻ���·\n"+
        	             "Ҳ�������ϣ������Բ���һ�е�Ҫ���ϵ����ߡ��ǰ׵���Ȼ�񿥣��������������ˣ�����\n"+
        	             "����ǧ��һ��ס�����׵���ʱ�������ȼ��䡣�ǵ�˫�������˴�ʼ��֧�ֲ�ס������ǧ��\n"+
        	             "ץס���غ��ģ�����Ҫ����ˤ�µ񱳣������������´����ڵ��ϣ����м�ˤ�����¡���������\n"+
        	             "�㱻����Ҳ�����Ի��֡��ۼ�����һ��Ҫˤ����ȣ�������ǡ������ư����վ��ɽ������\n"+
        	             "���ף���������Ŀ�ɿڴ����������á�����Σ���䣬���۵��Ź������˶����������ȥ����\n"+
        	             "����ǧ�ɶ��š������϶���Ȼ��ͷ����ʹ�����ֵֵ�����ֻ��ôһ���֣���һ�����Ľ����\n"+
        	             "��ȥ���������Һ���ɽ���´����������Ƶ��϶��ᣬ�ݿԻ�ণ����ֱ�ϡ�˫���Ŷ��ˣ�\n"+
        	             "����ȥ��\n"NOR,me);
	   me->delete_temp("quest/jindaoheijian/huangrong");
	   me->set_temp("quest/jindaoheijian/huangrong2",1);
	    return 1;
}

int ask_qqchi()
{
	object me= this_player();
	if (me->query_temp("quest/jindaoheijian/huangrong2")!=1) {
		command("say û��˵����");
		command("@@");
		return 1;
	}

	command("say û�뵽��ǧ�ɡ���ǧ���и����á��������귢������Ҳ���ܹ����ǣ�������ǧ��Ϯ�����ǣ����׵��ĵ���ɽ�ȡ�");
	message_vision(WHT"\n�㽫�ھ����������ǧ���Լ��һ��ظ����������߻��أ�\n"NOR,me); 
	command("disapp");
	command("consider");
	command("say ��λ�����ܰ���һ��æ�����������ȥһ����԰����һ�ƴ�ʦ��ϣ�����ܴ���ǧ��ȥȰ�����������������Թ��");
	command("say ����ԩԩ�౨��ʱ���ˣ�");
	me->delete_temp("quest/jindaoheijian/huangrong2");
	me->set_temp("quest/jindaoheijian/huangrong3",1);
	return 1;
}