// ������ħ by hongba

#include <ansi.h>
inherit NPC;
#define MIRROR_SYS "/quest/xyfm/sys/mirror_sys"
string ask_job();

void create()
{
	set_name(HIG"�µ���"NOR, ({ "zhang daoling", "zhang", "daoling"}));
	set("title", HIY"ĩ����ʦ"NOR);
        set("long", "���ǵ��ҵĸ��ˣ�������һ���鱦�ɵĽܳ������������\n");
	set("gender", "����");
        set("attitude", "peaceful");
        set("shen_type",1); 
	set("age", 50);
	set("per", 23);
       set("kar", 23);
	set("pur", 23);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("max_qi",9000);
	set("qi", 9000);
	set("max_jing", 6000);
	set("jing",6000);
	set("eff_jingli", 9000);
	set("jingli", 9000);
	set("max_neili", 9000);
	set("neili", 9000);
	set("jiali", 200);
	set("combat_exp", 5000000);
	
	set_skill("dodge", 180);
       set_skill("cuff", 180);
       set_skill("parry", 180);     
	set("shen", 5000);
        set("inquiry",([
                "job" :  (: ask_job :),
                 "����" : (:ask_job:),

 ]));

	
	setup();
	 carry_object("/d/wudang/obj/greenrobe")->wear();
	  carry_object("/clone/armor/shoes")->wear();
}

string ask_job()
{
   mapping fam;
    object me;
    object ob;
    me=this_player();
     fam= me->query("family");
if ( me->query_temp("xyfm_ask")) 
return "����ô���ʸ�û���أ�\n";
   if (me->query_condition("xyfm_job") >= 1)
       return "��л���⣬��������Ϣ�°ɣ�\n";

   if ((int)me->query("combat_exp") < 1500000)
       return "���ĺ����ϵ����죬��������Ϊ̫�ͣ�ĪҪ��Ϸ��֮��\n";
if ( !fam || fam["family_name"] != "�䵱��" && fam["family_name"] != "ȫ���"){
return "��λ"+RANK_D->query_respect(me)+"���ҵ���������������֪�˻��Ӻ�̸��";
}



    if ( me->query_condition("job_busy"))
{
                    if (me->query("job_name")=="������ħ")
{
                                   return "say ������ʱ��û�й�������ȥ����";
                                               
 }
                  
           
           return "say ����æ�ű�������ء�";
       
                                       
}

        
        command("say  ʱ�ƻ��ң�ս�����꣬����һ����Թ��Ұ��������ƽ���磬��ȥ���ҽ������ǣ�");
        command("say  Թ��֮˵���Թ���֮������������������Ҫ��ϸ����һ���źã�����С�ġ�");
me->set_temp("xyfm_ask",1);
return "���׼�����˵Ļ���������(yes)���������ȥ�����û׼���ã�������(no)��\n";
}
void init()
{
object me = this_player();
add_action("do_yes","yes");
add_action("do_no","no");
::init();
}
int do_no()
{
 object me = this_player();

 if ( me->query_temp("xyfm_ask")) {
me->delete_temp("xyfm_ask");
me->apply_condition("job_busy",5);
command("say  �ðɣ��Ժ���˵�ɡ�");
return 1;
}
}
int do_yes()
{
 object me = this_player();
object memory;
object *team;
int i;
if(MIRROR_SYS->query_room_amount() >= 20)
	{
		tell_object(me,"�����Ѿ�����̫�࣬��ӭ�´β��롣\n");
		return 1;
	}
        //ɾ���ɵĸ���
        memory = me->query_temp("mirror/mirror_memory");
        if(objectp(memory))
        {
                memory->delete("user_id");
        }

if ( me->query_temp("xyfm_ask")) {
me->delete_temp("xyfm_ask");
me->set_temp("xyfm_start",1);
 MIRROR_SYS->mirror(me);
       	return 1;
       
        me->move("d/mirror/guangchang");


}
}
