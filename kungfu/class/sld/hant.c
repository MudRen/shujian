// �鰲ͨ
// Modify Job By River@SJ 2001.1.21
// Update By lsxk@hsbbs for add ����hook
//by spierii@ty �������аٱ�quest
#include "ansi.h"

inherit NPC;
inherit F_MASTER;
int do_ask();
int do_fail();
int do_yao();
int do_jieyao();
int do_bishou();
int do_zhu();
int do_book();
int do_ask_buchang();
int checkvaild(mapping ob);
void checkbt();

void create()
{
	set_name("�鰲ͨ", ({ "hong antong","hong", "antong" }));
	set("long", "��������ϣ����޴��أ����϶����˰����ƣ���ª�Ѽ��������������̵Ľ�����\n");
	set("gender", "����");
	set("title", "�����̽���");     
	set("age", 66);       
	set("str", 35);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	set("per",10);
	set("combat_exp", 4500000);
	set("shen", -350000);
	set("attitude", "peaceful");
	set("max_qi",12000);
	set("max_jing",5000);
	set("neili",15000);
	set("max_neili",15000);
	set("eff_jingli",5000);
	set("jiali",200);
   set_skill("leg", 350);
   set_skill("shenlong-tuifa", 350);
	set_skill("force", 350);
	set_skill("dodge", 350);
	set_skill("parry",350);
	set_skill("strike",350);
	set_skill("shenlong-yaoli",350);
	set_skill("poison",200);
	set_skill("huagu-mianzhang", 400);
	set_skill("youlong-shenfa",380);
	set_skill("dulong-dafa",400);
	set_skill("literate",200);
	set_skill("dagger",380);
	set_skill("tenglong-bifa",380);
	set_skill("hook",250);
	set_skill("canglang-goufa",250);
        set_skill("shenlong-wudizhen",200);
  map_skill("leg", "shenlong-tuifa");
	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry","huagu-mianzhang");
	map_skill("poison","shenlong-yaoli");
	map_skill("dagger","tenglong-bifa");
	map_skill("hook","canglang-goufa");
	prepare_skill("strike","huagu-mianzhang");

	create_family("������",1, "����");
	
	set("env/huagu",10+random(10));
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "strike.bujue" :) ,
		(: perform_action, "strike.huagu" :) ,
	}));      
	
	set("inquiry", ([
		"task":         (: do_ask :),
		"quest":        (: do_ask :),
		"����":         (: do_ask :),
		"renwu":        (: do_ask :),
		"job":          (: do_ask :),
		"ȡ������":     (: do_fail :),
		"cancel":       (: do_fail :),
		"��̥�׽���":   (: do_yao :),
		"yao":          (: do_yao :),
		"jieyao":       (: do_jieyao :),
		"��ҩ":         (: do_jieyao :),
		"ذ��":         (: do_bishou :),
		"bishou":       (: do_bishou :),
		"�ۻ�����":     (: do_zhu :),
		"��ʮ���¾�":   (: do_book :),
              "����":   (: do_ask_buchang :),
	]));

	set_temp("apply/damage", 88);
	set_temp("apply/dodge", 188);
	set_temp("apply/attack", 188);
	set_temp("apply/armor", 288);
	
	set("bishou",3);
	set("bstime",time());
	setup();
	carry_object("/d/sld/npc/obj/slp")->wear();       
	
	if(clonep(this_object())) call_out("checkbt",15*60);
}

void attempt_apprentice(object ob)
{
	mapping myfam;

	myfam = (mapping)ob->query("family");
	if(!myfam || myfam["family_name"] != "������")
		command("say ��Ǳ��̵��ӣ�������ȥ������ʹ��̰ɡ�");
	else if(ob->query("shen",1) > -100000)
		command("say �㻹�����ĺ���������ȥ��ɱ�����׵����˰ɡ�");
	else if(ob->query_skill("dulong-dafa",1) < 150 || ob->query_skill("huagu-mianzhang",1) < 150)
		command("shake "+ob->query("id"));
	else if(ob->query_temp("marks/hant"))
		command("say ���������õ���ô��");
	else {
		command("say �����������ɱ������������������ڵ������������ҿ��Կ�������Ϊͽ��");
		ob->set_temp("marks/hant",1);
	}
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	object hw;

	myfam = (mapping)ob->query("family");
	if(!myfam || (myfam["family_name"] != "������")) return 0;
	if(!ob->is_apprentice_of(this_object())) return 0;
        if( ob->query("shen",1)>100000 ) {
		command("say �ߣ��㾹Ȼ�ҺͰ׵����˸���һ���ǲ��ǲ�����ˣ���ȥ���ݺú÷�ʡ��ʡ�ɣ�");
		if(!objectp( hw =find_object("/d/sld/heiwu")))
			hw=load_object("/d/sld/heiwu");
		ob->set("in_heiwu",time());
		ob->move(hw);        
		return 0;
	}
	return 1;
}

int accept_object(object me, object ob)
{
	if( ob->query("id") == "shenglong dan" ) {
		if(me->query_temp("marks/dragon",1)) {
			command("say �ðɣ����Ȼ�����õ������������Ҿ����������ҵĵ����ˡ�");
			command("recruit " + me->query("id"));
			me->set("title","�����̵ڶ�������");	
			if( !me->query("sld/addexp")) {
				me->add("combat_exp", 10000);
				me->set("sld/addexp",1);
			}
			me->delete_temp("marks/dragon");
			me->delete_temp("marks/hant");
			call_out("destructing", 1, ob); 
			return 1;
		}
		else if(me->query_temp("marks/hant",1)) {
			command("say �������Ū�˿żٵ���ƭ�ң�");
			me->fight_ob(this_object());
			this_object()->kill_ob(me);
			me->delete_temp("marks/hant");
			call_out("destructing", 1, ob); 
			return 1;
		}
	}
	
	if(userp(ob)) return 0;
	if(ob->query("id") == "hook book") return 0;
	if(ob->query("unique")) {
		tell_object(me,"�鰲ͨ����ٺ�Ц�����ܺã��ܺã�\n");
                me->add("shen", -(100000 + random(3000)));
		ob->move("/d/sld/md1");
		call_out("destructing", 0, ob); }
	else {
		return 0;
	}
	return 1;
}

void destructing(object ob)
{
	if(ob) destruct(ob);
}

// ����hook & canglang-goufa   By lsxk@hsbbs
int do_ask_buchang()
{
   object me = this_player();
   mapping myfam;
   myfam = (mapping)me->query("family");
   if(!myfam || myfam["family_name"] != "������")
           return notify_fail("�鰲ͨ˵��������Ҫ������ʲô����\n");

   if(me->query("sld/hook����"))
           return notify_fail(HIR"���˲�Ҫ̰������!\n"NOR);

   me->set_skill("hook",200);
   me->set_skill("canglang-goufa",200);
   me->set("sld/hook����",1);
   write("�������!\n");
   return 1;
}
int do_book()
{
	object *obs;
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "������")
		return notify_fail("��Ҫ��ʲô��\n");
	
	if(me->query_temp("sld/bailong"))
	{
		command("? "+getuid(me));
		return 1;
	}
	if(me->query("family/master_id")!="hong antong")
	{
		command("say ����ҵ��ӣ��������ʲô��");
		return 1;
	}
	obs = filter_array(children(USER_OB),(:clonep:));
	obs = filter_array(obs,(:$1->query_temp("sld/bailong"):));	
	if(sizeof(obs)>2)
	{
		command("say �Ѿ����˰���Ѱ����ʮ���¾��ˡ�");
	}
	command("ok");
	command("say �������Ļ��ǵñ���������£�����������Ǳ��̰�������ʹ��");
	command("whisper "+getuid(me)+" Ԥף����ʹ����ȡ����ʮ���¾�Ϊ�ҽ̽�����ҵ��");
	me->set_temp("sld/bailong",1);
	me->set_temp("sld/bailong_exp",me->query("combat_exp"));
	me->set_temp("sld/bailong_time",uptime());
	me->set("title",HIW"�����̰���ʹ"NOR);	
	return 1;
}

int do_zhu()
{
	object ob,me=this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "������")
		return notify_fail("��Ҫ��ʲô��\n");
	
        if ( present("xianghuang zhuzi", me) )
        {
        	command("say ����ģ�����Τ��С�ӻ�̰��");
        	return 1;
	}
	if(me->query("quest_kill/quests")<100)
	{
		command("say ��Ϊ��������ʲô��");
		return 1;
	}
	ob = unew("/d/sld/npc/obj/zhuzi");
	if(!ob)
	{
		command("say ���S���ӱ����Ѿ������������ˡ�");
		return 1;
	}
	if(!clonep(ob)){
		command("say ���S���ӱ����Ѿ������������ˡ�");
		return 1;
	}
        if(clonep(ob) && ob->violate_unique()){
                destruct(ob);         
		command("say ���S���ӱ����Ѿ������������ˡ�");
		return 1;
        }
	command("nod");
	ob->move(this_object());
	command("give 1 to "+getuid(me));
	return 1;
}
 
int do_bishou()
{
	object ob = this_object() , me = this_player();
	object bs;
	mapping myfam;

	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "������")
		return notify_fail("��Ҫ��ʲô��\n");
		
	if((time()-ob->query("bstime")) > 900 ){
		ob->set("bstime",time());
		ob->set("bishou",3);
        }
        
        if( me->is_apprentice_of(ob)
	 && me->query_skill("huagu-mianzhang", 1) >=150
	 && me->query_skill("shenlong-tuifa", 1) >= 150
	 && me->query_skill("canglang-goufa", 1) >= 150
	 && me->query_skill("dulong-dafa", 1) >= 150 ){
		if(me->query_temp("get_bishou"))
			return notify_fail("�鰲ͨ˵���������Ѿ�������ذ����ô����ô����Ҫ�ˣ�\n");
		if(ob->query("bishou") <= 0)
			return notify_fail("�鰲ͨ˵�������������û��ذ�ף��������Ҫ�ɡ�\n");
		bs = new(BINGQI_D("dagger/sld_bishou"));
		if(!objectp(bs))
			return notify_fail("�鰲ͨ˵�������������û��ذ�ף��������Ҫ�ɡ�\n");
		bs->move(me);
		ob->add("bishou",-1);
		message_vision("�鰲ͨ˵�����úõ�Ϊ���̳��������������ģ����ϣ�����$Nһ��ذ�ס�\n",me);
		me->set_temp("get_bishou",1);
		return 1;
	}
	else
		return notify_fail("��Ҫ��ʲô��\n");
}
   
int do_ask()
{
	object me,lp,hw;
	mapping myfam,quest;
	string prev;

	me=this_player();
		
	myfam = (mapping)me->query("family");
	if (!myfam || myfam["family_name"] != "������")
		return notify_fail("��Ҫ��ʲô��\n");

	if(me->query("shen",1) > 0){
		command("say �ߣ��㾹Ȼ�ҺͰ׵��и���һ���ǲ��ǲ�����ˣ���ȥ���ݺú÷�ʡ��ʡ�ɣ�");
		if(!objectp(hw=find_object("/d/sld/heiwu")))
			hw=load_object("/d/sld/heiwu");
		me->set("in_heiwu",time());
		me->move(hw);        
		return 1;
	}

	if( me->query_condition("job_busy")) {
		command ("say ��С�Ӿ���͵͵���������ɵ����񣬻����������������ȥô��");
		return 1;
	}
        
	if(me->query("quest_kill/questing")==1) {
		command("say ���Ȱ�ǰһ�����������˵��"); 
		return 1;
	}

	if((time()-me->query("quest_kill/ok_time")) < 300) {
		command("say ������Ϣһ�°ɡ�"); 
		return 1;
	}   

        if ( me->query("job_name") == "������" && me->query("combat_exp") >= 100000){
		command("say ���������������Ϣһ�°ɡ�");
		return 1;
	}
	/*	
	if(random(me->query("quest_kill/quests"))>200
	&& random(me->query("pur"))>25
	&& !me->query("quest/baibian")
	&& !me->query_temp("quest/baibian")
	&& random(me->query("kar"))>20
	)
	{
		command("bite");
		command("say ����ͻȻ���𱾽̵�һ������ˣ���ȥ����ɱ������");
		command("whisper "+getuid(me)+" ��������ΤС����Ϊ�����̲�С��");
		me->set_temp("quest/baibian",1);
		if ( present("su quan", environment(me)) )
		{
			present("su quan", environment(me))->force_me("iddle");
			command("kill1");
		}
		log_file("quest/baibian",sprintf("%-8s(%-8s) �õ�������аٱ�Ļ��ᡣ",me->query("name"),getuid(me)),this_object());
		return 1;
	}
		*/
	if(me->query("combat_exp") > 2000000) {
		command("say �Ѿ�û��ʲô�����ʺ������ˡ�");
		return 1;       
	}
	
	if( random(2) == 1 ) {
		if(mapp(quest=TASK_D->get_quest(me, 0, "����", "������"))) {
			if(checkvaild(quest) && (!(prev=me->query_temp("prev",1)) || prev!=quest["id"])) {
				if(me->query("quest_kill/cancel"))
                                        me->set("quest_kill/ok_time",me->query("quest_kill/start_time"));
                                else
                                        me->set("quest_kill/ok_time",time());

                                me->delete("quest_kill/cancel");
                                me->set("quest_kill/id",quest["id"]);
                                me->set("quest_kill/name",quest["name"]);
                                me->set("quest_kill/start_time",time());
                                me->set("quest_kill/exp",1);
                                me->set("quest_kill/questing",1);
                                
                                lp=new("/d/sld/npc/obj/suomp");
                                lp->set("long",lp->query("long")+HIR"�������"+quest["place"]+quest["name"]+"�����֡�\n"NOR);
                                lp->move(me);   
                                command("say "+quest["name"]+"���뱾�����ԣ�����ȥ"+quest["place"]+"����ɱ�ˣ�");
                                message_vision("�鰲ͨ�ó�һ�������ƣ������������"+quest["place"]+quest["name"]+"�����֣�������$N��\n",me);
                                me->apply_condition("job_busy", 9);
                                me->set("job_name","������");
                                me->set_temp("prev",quest["id"]);
                                return 1;                               
                        }
                }      
        }
        if(mapp(quest=TASK_D->get_quest(me, 0, "�л�", "������")))
        {
                if(checkvaild(quest) && 
                  (!(prev=me->query_temp("prev",1)) || prev!=quest["id"])) {
                        if(me->query("quest_kill/cancel"))
                                me->set("quest_kill/ok_time",me->query("quest_kill/start_time"));
                        else
                                me->set("quest_kill/ok_time",time());
                        me->delete("quest_kill/cancel");
                        me->set("quest_kill/id",quest["id"]);
                        me->set("quest_kill/name",quest["name"]);
                        me->set("quest_kill/start_time",time());
                        me->set("quest_kill/exp",1);
                        me->set("quest_kill/questing",1);
                        me->set_temp("zhaohun/times",0);
                        if(me->query_temp("quest/huilu",1)!=0)
                                me->delete_temp("quest/huilu");  
                        lp=new("/d/sld/npc/obj/zhaohp");
                        lp->set("long",lp->query("long")+HIR"�������"+quest["place"]+quest["name"]+"�����֡�\n"NOR);
                        lp->move(me);
                        command("say "+"����������ȥ"+quest["place"]+"�跨��"+quest["name"]+"��˳���̣�");
                        message_vision("�鰲ͨ�ó�һ���л��ƣ������������"+quest["place"]+quest["name"]+"�����֣�������$N��\n",me);
                        me->set_temp("prev",quest["id"]);
                        me->set("job_name","������");
                        me->apply_condition("job_busy", 9);
                        return 1;                               
                }
        }                                       
        command("say ����û����������������ɡ�");
        return 1;
}

int do_fail()
{
        int times,cf,qi;
        object me=this_player();
        object obj,hw;

        if(me->query("quest_kill/questing")!=1)
                return notify_fail("�����ʲô��\n");

        times=(time()-me->query("quest_kill/start_time"))/60;

        if(times<10) {
                if(me->query_temp("quest_kill/failin5",1)>1) {
                        me->delete_temp("quest_kill/failin5");
                        command("say ��������ο��������ǲ��ǲ�����ˣ������ҵ����ݴ���ȥ��");
                        if(!objectp(hw=find_object("/d/sld/heiwu")))
                                hw=load_object("/d/sld/heiwu");
                        me->set("in_heiwu",time());
                        me->move(hw);
                        return 1;
                }

                if(me->query_temp("quest_kill/failin5",1)==0)
                        me->set_temp("quest_kill/failin5",1);
                else
                        me->set_temp("quest_kill/failin5",2);    
                command("say ��ô�������뿹�����ɣ���");
                return 1;
        }

        if(times > 30)   times=30;
        cf = 2000*30/times;
        qi=me->query("max_qi");
        if(cf>=qi) cf=1; else cf=qi-cf;
        me->set("qi", cf);

        command("say ��ô�����鶼�첻�ˣ�Ҫ����������֮�˺��ã�");
        message_vision("�鰲ͨһ�ư�$N��÷��˳�ȥ��\n",me);

        me->set("quest_kill/questing",0);
        if(me->query_temp("quest_kill/failin5",1)!=0)
                me->delete_temp("quest_kill/failin5");
        if(objectp(obj = present("suomingpai", me))) {
                destruct(obj);
        }
        if(objectp(obj = present("zhaohunpai", me))) {
                destruct(obj);
        }
        me->set("quest_kill/cancel",1);
        return 1;
}

int checkvaild(mapping ob)
{
        string* ffid= ({ "young monk","mu ren","zhu cong",
                       "zhu wanli","ping wei","gui tong","lao ren","qiao zhujiang",
                             "shen laoban","leitai npc","lao ban","mengmian nuzi",
                             "daojue chanshi","huang zhe","jin ren","wu zhanglao",
                             "zhu danchen","yang guo","xiao longnu","biaoshi","biaotou", 
                             "dizi","wulun npc","huang yaoshi","feng qingyang" });
        string* ffname= ({ "С����","ľ��","���","������","ƽ��",
                           "���ݹ�ͯ","��������","����","���ϰ�","��ֱ̨��Ա","�����ϰ�",
                           "����Ů��","������ʦ","����","����","�ⳤ��","�쵤��","���",
                           "С��Ů","��ʦ","��ͷ","����","ľ��","��ҩʦ","������" });
        int i;
        object target;
        string npcfile;
        object* living;

        living=livings(); 
        for(i=0;i<sizeof(living);i++)
        {
                if(living[i]->query("id")==ob["id"] && living[i]->query("name")==ob["name"])
                {
                        target=living[i];
                        break;
                }
        }
        if(i>=sizeof(living))
                return 0;       
        if((target->query("combat_exp")<100000) && 
           (target->query("family/family_name")=="������"))
                return 0;
        npcfile=file_name(target);
        if(strsrch(npcfile,"/kungfu/class/shaolin/")>=0)
        {
                if(strsrch(target->name(1),"Բ")>=0)
                        return 0;
        }
        if(strsrch(npcfile,"/clone/npc/zhong-shentong")>=0)
                return 0;
        if(strsrch(npcfile,"gumu/")>=0) return 0;
        for(i=0;i<sizeof(ffid);i++)
        {
                if(ffid[i]==ob["id"] && ffname[i]==ob["name"])
                {
                        return 0;
                }
        }
        if((ob["id"]=="killer") || (ob["id"]=="stealer")
          || (ob["id"]=="cateran") 
          || (ob["id"]=="menmianren") || (ob["id"]=="mengmian ren"))
                return 0;
        return 1;
}

int do_yao()
{
        object me=this_player();
        object yao;
        int jobs;
        mapping myfam;
        
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "������")
                return notify_fail("��Ҫ��ʲô��\n");
	
	if(present("baotaiyijinwan",me))
	{
		command("say �����ϲ�����ô��");
		return 1;
	}
        if(me->query("quest_kill/btyao")){
                command("say ���Ѿ��Թ���̥�׽��裬�����ٳ��ˡ�");
                return 1;       
        }
        if(me->query("combat_exp") <= 1500000){
                if(!me->query("quest_kill/quests")) {
                        command("say ���������û��ɹ�ʲô���񣬾�Ȼ����Ҫ��̥�׽��裿��");
                        return 1;
                }
                jobs=me->query("quest_kill/quests");
                tell_object(me,"����������"+jobs+"������\n");
                jobs=300-jobs;
                if(jobs > 0) {
                        command("say �������ɵ����񲻹��࣬�в����Եõ���̥�׾��衣");
                        return 1;
                }
        }
        me->set("quest_kill/quests",0);
        yao = new("/d/sld/npc/obj/btyao");
        command("nod");
        if(!yao->move(me))
                yao->move(environment(me));
        return 1;
}

int do_jieyao()
{
        object me=this_player();
        object yao;
        int jobs;
        mapping myfam;
        
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "������")
                return notify_fail("��Ҫ��ʲô��\n");
	if(present("jie yao",me))
	{
		command("say �����ϲ�����ô��");
		return 1;
	}
	
        if(me->query("combat_exp")<=2000000){
                if(!me->query("quest_kill/quests")){
                        command("say ���������û��ɹ�ʲô���񣬾�Ȼ����Ҫ��̥�׽���Ľ�ҩ����");
                        return 1;
                }
                jobs=me->query("quest_kill/quests");
                tell_object(me,"����������"+jobs+"������\n");
                if(jobs < 100){
                        command("say �������ɵ����񲻹��࣬�в����Եõ���̥�׽���Ľ�ҩ��");
                        return 1;
                }
                if(!me->query("quest_kill/fazuo")) {
                        command("say �����ں�����Ҫ��̥�׽���Ľ�ҩô��");
                        return 1;
                }
                if(me->query("age")==me->query("quest_kill/fz_year")
                && me->query("month")==me->query("quest_kill/now_month") )
                {
                	command("en "+getuid(me));
                	return 1;
                }
        }
        me->set("quest_kill/quests",0);
        command("nod");
        yao=new("/d/sld/npc/obj/jieyao");
        if(!yao->move(me))
                yao->move(environment(me));
        return 1;
}

void checkbt()
{
	object * usrlist;
	int i;
	//,dis;
	string tit;

	remove_call_out("checkbt");
	call_out("checkbt",15*60);
	
	usrlist = filter_array(users(),(:$1->query("family") == "������":));
        for(i=0;i<sizeof(usrlist);i++) {
        	if(usrlist[i]->query_temp("sld/bailong"))
        	{
        		if(((usrlist[i]->query("combat_exp")-usrlist[i]->query_temp("sld/bailong_exp")+100)*60/(uptime()-usrlist[i]->query_temp("sld/bailong_time")))>=20)
        		{
        			usrlist[i]->set("title",HIW"�����̰���ʹ"NOR);
        			continue;        			
        		}
        		usrlist[i]->delete_temp("sld/bailong");
        		usrlist[i]->delete_temp("sld/bailong_exp");
        		usrlist[i]->delete_temp("sld/bailong_time");
        		tell_object(usrlist[i],HIR"������ɸ봫��֪ͨ�㣺����Ϊ��ʱ��͵��������ʹ����Ѿ���ȡ����\n");
        	}
                if(usrlist[i]->query("family/generation")<=2 && usrlist[i]->query("combat_exp")>=500000) {
	                if(usrlist[i]->query("combat_exp")>=4000000) tit=HIB"�����̸�����"NOR;
        	        else if(usrlist[i]->query("combat_exp")>=3600000) tit=HIG"�����̳���"NOR;
                	else if(usrlist[i]->query("combat_exp")>=3200000) tit=HIR"�����̳���"NOR;
                	else if(usrlist[i]->query("combat_exp")>=2800000) tit=HIY"�����̳���"NOR;
                	else if(usrlist[i]->query("combat_exp")>=2400000) tit=HIW"�����̳���"NOR;
                    	else if(usrlist[i]->query("combat_exp")>=2000000) tit="�����̳���";
                	else if(usrlist[i]->query("combat_exp")>=1800000) tit=HIG"�����̻���"NOR;
                	else if(usrlist[i]->query("combat_exp")>=1600000) tit=HIR"�����̻���"NOR;
                	else if(usrlist[i]->query("combat_exp")>=1400000) tit=HIY"�����̻���"NOR;
                	else if(usrlist[i]->query("combat_exp")>=1200000) tit=HIW"�����̻���"NOR;
                	else if(usrlist[i]->query("combat_exp")>=1000000) tit="�����̻���";
                	else if(usrlist[i]->query("combat_exp")>=900000) tit=HIG"�����̻�������"NOR;
                	else if(usrlist[i]->query("combat_exp")>=800000) tit=HIR"�����̻�������"NOR;
                	else if(usrlist[i]->query("combat_exp")>=700000) tit=HIY"�����̻�������"NOR;
                	else if(usrlist[i]->query("combat_exp")>=600000) tit=HIW"�����̻�������"NOR;
                    	else tit="�����̻�������";
                       	usrlist[i]->set("title",tit);
                }
                /*                
                if(usrlist[i]->query("quest_kill/btyao") && !usrlist[i]->query("quest_kill/jieyao")) {
                        usrlist[i]->set("quest_kill/jieyao",1);
                        usrlist[i]->set("quest_kill/bt_year",usrlist[i]->query("age"));
                        usrlist[i]->set("quest_kill/bt_month",usrlist[i]->query("month"));
                }
        	else if(usrlist[i]->is_ghost())  continue;
                else if(usrlist[i]->is_fighting())  continue;
                else if(usrlist[i]->query("quest_kill/jieyao"))
                {
                        me=usrlist[i];
                        dis=(me->query("age")-me->query("quest_kill/bt_year"))*12+
                            (me->query("month")-me->query("quest_kill/bt_month"));
               		if(dis>=13)
                        {
                   		if(me->query("death_times")>me->query("quest_kill/dts"))
                   		{
                       			me->set("quest_kill/dts",me->query("death_times"));
                       			me->add("quest_kill/bt_year",1);
                   		}
                                if(me->query_temp("jytell",1)==0)
                                {
                                        tell_object(me,"���Ѿ�����һ��û�Խ�ҩ�ˣ�\n");
                                        me->set_temp("jytell",1);
                                }
    				if((me->query("quest_kill/jieyao")==1)
    				|| ((time()-me->query_temp("jyfz",1))>900))
                                {
                                        tell_object(me,"��ͻȻ�е�һ���ʹ�Ӹ�����ȫ��Ѹ����ɢ��\n");
                                        me->add("eff_jingli", -me->query("eff_jingli")/10);
                                        me->set("jingli",0);
                                        me->set("neili",0);
       					me->set_temp("jyfz",time());
                                        me->receive_wound("qi", me->query("eff_qi")/2);
                                        me->receive_wound("jing", me->query("eff_jing")/2);
                                        me->unconcious(); 
                                        me->set("quest_kill/jieyao",2);
                                }
                        }
                   else if (dis==12) {
                                if(!me->query_temp("jytell"))
                                {
                       			tell_object(me,"���Ѿ�һ��û�Խ�ҩ�ˣ�\n");
                                        me->set_temp("jytell",1);
                                }
                   		if(!me->query("quest_kill/dts"))
                   			me->set("quest_kill/dts",me->query("death_times"));
                        }
                }
                */
        }
}
