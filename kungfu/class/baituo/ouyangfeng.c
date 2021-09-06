// /u/snowman/npc/oyf1.c ŷ����
// by snowman 12.feb.98

#include <ansi.h>
inherit NPC;
void create()
{
       set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }) );
       set("gender", "����" );
       set("title", BLU "�϶���" NOR);
       create_family("����ɽׯ", 1, "ׯ��");
       set("shen_type", -1);
       set("age", 70);
       set("per", 20);
       set("long","���߹���һ�������������ף�������ꪣ�һ��������̡����ƣ�\n"+
		"������ֱ��Ѿõ��常ŷ���档\n" );
       set_temp("hide_level", 45+random(6));
       set("inquiry", ([
                "ŷ����" : "ŷ���桢ŷ���棬������������ͦ��ġ�����\n",
                "���߹�" : "���߹���������Ҳ�졣\n",
                "��󡹦" : "��󡹦�;����澭���ǵ��������湦�����µĶ�����Ϊ�ǡ�\n",
       	]));
       	setup();       
       	carry_object(ARMOR_D("cloth"))->wear();
       	add_money("silver", 10);
}


void kill_ob(object me)
{
	command("pat " + me->query("id"));
        command("say ��������ô��Ϊ��������ι���ˣ�");
        me->remove_all_enemy();
        this_object()->remove_all_enemy();
}

void init()
{
        object ob = this_player();   
        if (!stringp(query("startroom")) ) return;
             
        add_action("do_lian","yanlian");
        if(ob->query("oyf_son") && ob->query("oyf/hamagong") == 1) 
                call_out("do_angry", 5, ob);          
        else{
             	command("look " + ob->query("id"));
             	command("say ι�������Ķ�����" + RANK_D->query_rude(ob) + "���߿����߿���");
             	command("kick " + ob->query("id"));
             	message_vision("$N��ѽһ�����Ѿ���ŷ����ɽ����˳�ȥ��\n",ob);
             	ob->move("/d/gumu/shulin2");
             	message_vision(ob->name() + "����һ�Ŵ�����������˳�����\n",ob);
             	ob->receive_wound("qi", 50, "��ŷ����һ����");
             	return;
        }
}

void do_angry(object ob)
{
        if( !ob ) return;
        if( environment(ob) != environment() ) return;
        command("angry " + ob->query("id"));
        command("say �����������Ķ�ȥ�ˣ�Ϊ�����ҵ���ÿ࣡");  
        call_out("do_back", 180);     
        call_out("ask_test", 10, ob);               
}

void ask_test(object me)
{
	if( !me ) return;
        if( environment(me) != environment() ) return;
        command("hug " + me->query("id"));
        command("say ����������书�����ò����ٺ�Ҳû���ˡ�������(yanlian)��󡹦�������ơ�");       
        me->set_temp("oyf_test", 1);         
}

int do_lian()
{
      	object me = this_player();             
      	if( !me->query_temp("oyf_test") ) return 0;
      
      	tell_object(me, HIC "���ʱ����һ˵����Ȼ�հ졣\n" NOR );      
      	message_vision("$N���¶������ӣ������󡹦����ֻ��$Nʹ�û��Ž��أ����Ǻÿ���\n",me);
      	me->delete_temp("oyf_test");  
      	call_out("oyf_laugh", 6, me);                 
      	return 1; 
}

void oyf_laugh(object me)
{
	if( !me ) return;
        if( environment(me) != environment() ) return;
        
        command("haha " + me->query("id"));
        command("say �ÿ����ÿ������ǲ��Ծ����п������á�");
        command("say �Ұ����о��Ͼ���������գ�");
        tell_object(me, "\nŷ���浱��ָ�ֻ��š����ϲ�����˵������������\n");      
        call_out("oyf_teach", 10, me);       
}

void oyf_teach(object me)
{
      	int i,lvl=1;
	mapping skills;
	string *sk;
	
	if( !me ) return;
        if( environment(me) != environment() ) return;
      	command("say ����ȭ�����Ұ���ɽׯ����֮�أ�����������ͷ����Ī�ó�����Ū��");
       	tell_object(me, HIC "\nŷ������㽲���˰���ɽׯϵ����ѧ��Ҫ��������\n" NOR );  
      	me->add("max_neili", 100);  
      	tell_object(me, "����ڹ���Ϊ����ˣ�\n"); 
      	tell_object(me, "��ѧ���������ȷ���\n"); 
      	tell_object(me, "��ѧ��������ȭ����\n"); 

        me->set_skill("lingshe-zhangfa", me->query_skill("hamagong", 1));
        me->set_skill("lingshe-quanfa", me->query_skill("hamagong", 1));
        me->set_skill("cuff", me->query_skill("hamagong", 1));
        me->set_skill("staff", me->query_skill("hamagong", 1));
me->add("oyf/hamagong", 1);   
        skills = me->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]]+=lvl;
        }
	me->add("combat_exp",me->query("combat_exp")/(50-lvl)+lvl);
        me->add("shen", me->query("shen")/(10-lvl));   
    me->set("title",HIW"����ɽׯ"MAG"��󡹦����"NOR);
         tell_object(me, "��Ĺ�������ˣ�\n");
         tell_object(me, "�������常�Ľ̵�,������Щ�ط���̫���ף�\n");
	log_file("quest/hamagong", sprintf("%8s%-10sѧ�����ɽׯ��ѧ�����õ�������\n",
		me->name(1), "("+me->query("id")+")" ), me);
	call_out("do_back", 15);    
}

void do_back(object me)
{                 
      	message_vision(HIY"\nֻ��$NͻȻ˫Ŀ���ɣ�һ��Ҳ���������ﲻס������������澭�������澭����\n\n"NOR, this_object());
      	call_out("do_leave", 4);             
}

void do_leave()
{
      	message_vision("$NͻȻһ����������ת�����ӣ���ͷ�ŵأ���У�������˭������˭��ŷ���浽�ǡ�ȥ�ˣ���\n", this_object());
      	message_vision("����$N˫�����裬���Ӽ�ת��������·��������ĳ��������ʧ�ˡ�\n", this_object());            
      	destruct(this_object());      
}
