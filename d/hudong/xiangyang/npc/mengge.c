//��������ˢ�µص㣬�������ǡ� By lsxk@hsbbs 2007/7/10
#define JOB_CHECK_PLACE "/d/xiangyang/cross2"

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#define HDJOB "/adm/daemons/hdjob.c"
#define HD_TEST 1
#define MAX_HDNUM 40
int ask_me1();
int check_player(object me,string arg);

void create()
{
    	set_name("�ɸ�", ({ "meng ge", "meng", "ge" }));
    	set("title","�ɹ�Ԫ˧");
    	set("gender", "����");
    	set("long", "���Ǵ˴θ�������������ɹ�Ԫ˧��\n");
    	set("age", 25);
    	set("str", 30);
    	set("int",20);
    	set("con",30);
    	set("dex",20);
    	set("combat_exp", 300000);
    	set("attitude", "friendly");
    	set("max_qi",2000);
    	set("max_jing",1000);
    	set("neili",2000);
    	set("max_neili",2000);
    	set("qi",2000);
    	set("jing",1000);
    	set("jingli",1000);
    	set("score", 100);
    	set("unique", 1);
        set("no_get", 1);
    	set("no_quest",1);

    	set_temp("special_die",1);
    	set_temp("xyjob/mg_attack",1);
    	set_temp("living", 1);

    	set_skill("force", 100);
    	set_skill("dodge", 100);
    	set_skill("parry", 100);
        set_skill("yijin-jing", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("blade", 100);
        set_skill("xiuluo-dao",100);
        set_skill("buddhism", 100);
        set_skill("literate", 100);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "xiuluo-dao");
        map_skill("blade", "xiuluo-dao");

// ��������
        set("sljob",3);
        set("xxjob",4);
        set("xsjob",2);
        set("gjob",1);
        set("job",6);

        set("inquiry", ([
 "��������" : (: ask_me1 :),        
        ]) );

        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/armor/armor")->wear();
}
int ask_me1()
{
int i, a_exp = 0, d_exp= 0;
object ob =this_object();
object *obj;
      object me = this_player();
           if(!ob->query("hd_start")){ 

           command("say �Ҿ�����������ս���������þ�Ҫ����������");
             return 1; } 
     if(me->query_condition("killer")){
           command("say ������ͨ���У�̫���ۣ�����ȡ��ͨ���������ɣ�");
             return 1;
         }
             if(base_name(environment(ob))!="/d/hudong/xiangyang/attack"){
            command("say �ҳ������⣬�������");
            return 1; } 
             if(me->query("combat_exp") < 100000){
            message_vision("$N��$n˵������λ"+RANK_D->query_respect(me)+"��ս���ն��㻹�ǻ�ȥ�úö����ɣ�\n",ob,me);
           return 1; } 
             if(me->query_temp("��������/������ս/ask_ok")==2){
             command("say ���Ѿ���Э�����ɹ��ȷ����ȡ�����ˣ��Ͽ�����׼���ɣ�");
             return 1; } 
             if(me->query_temp("��������/������ս/ask_ok")==1){
           command("say �����ģ����Ī���������ɹ����ļ�ϸ��");
             return 1;         } 
            

             message_vision(CYN"\n$N������Ц����"+RANK_D->query_respect(me)+"������æ���ι���ͼ��ֹ�Ҿ���ȡ���������̾�Ҫ����ˡ�\n"NOR, ob, me);
             message_vision(CYN"\n$N��$n˵������Ȼ��ˣ�"+RANK_D->query_respect(me)+"�͸Ͽ���ȥ׼��׼���ɣ��Ҿ����Ͼ�Ҫ�����ˡ�\n"NOR, ob, me);
             me->set_temp("��������/������ս/ask_ok",2);
 me->set_temp("��������/������ս/attack",1);

 me->set_temp("title",HIR"�ɹ��ȷ�"NOR);
                      return 1;
}
 int check_player(object me,string arg)
{
	if(userp(me) && me->query_temp(arg))
		return 1;
		else
		return 0;
}
