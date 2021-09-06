// By Spiderii ���±���
inherit NPC;
#include <ansi.h>
int ask_yirong();
int ask_yirong2();
int ask_yirong3();
int ask_help();

void create()
{
        set_name("����", ({ "a zhu", "a", "zhu" }));
        set("gender", "Ů��");
        set("age", 20);
        set("long","���Ǹ���ʮ�������Ů��һ��������˵��������ɣ�\n"+
                   "��������,��Ȼ�㲻������,������һ����ζ����ͷ��\n");
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 26);
        set("per", 25);
        set("unique", 1);
        set("location", 1);
        set("combat_exp", 14000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	 set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
	 set("jiali",30);
	 set("score", 8000);
        set_skill("cuff", 50);
	 set_skill("parry",50);
	 set_skill("yanling-shenfa",50);
        set_skill("dodge", 50);
	 set_skill("force",50);
	 set_skill("shenyuan-gong",50);

	 map_skill("force","shenyuan-gong");
	 map_skill("dodge","yanling-shenfa");      
         
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);


        set("inquiry", ([           
                     "����" : (: ask_yirong2 :),
                     "��Ը" : (: ask_help :),
                     "������" : (: ask_yirong :),
                     "��Ƥ���"  : (: ask_yirong3 :),

        ]));
        setup();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();

}

int ask_yirong()
{          
       object me = this_player();
        string msg;
        msg = HIY"����˵��:һ����ν����������ʵӦ�ý�����װ����\n"NOR;
        msg+= HIY"����˵��:�������ٷ������룬��ͬ���·�����һ���˱�ɲ�ͬ����һ���ˡ�\n"NOR;
        msg+= HIY"����˵��:������ν����������ֱ����С���ӵ����⣬Ҳ������µ�һ�֡�\n"NOR;
        msg+= HIY"����˵��:��������������Ƚ�����,�������\n"NOR;
        message_vision(msg, me);
        me->set_temp("azhu/yirong1",1);
        return 1;
}

int ask_yirong2()
{ 
        object me = this_player();
        string msg;
        if (me->query_temp("azhu/yirong1")==1)
        {
        msg = HIY"����˵��:����һЩ��������,Ҫ�󷱶�,��һ��һϦ����ѧ�á�\n"NOR;
        msg+= HIY"����˵��:��������ò��ͬ������˵��ȫ����Ϊ����ĸ��첻ͬ����ɡ�\n"NOR;
        msg+= HIY"����˵��:������������ͨ����Ҫ�����ǹ�,���������༼���书���Ը���,���ɴﵽ���������Ч����\n"NOR;
        msg+= HIY"����˵��:�뵱����ֻƾһ����Ƥ���,��������Ŀ��֮��,�����������Ե�����֮��--�׽!\n"NOR;
        msg+= HIY"����˵��:�ɼ���Ľ�����ҳ� �Ա�֮��,��ʩ���� ֮��,���������ν��������!\n"NOR;
        message_vision(msg, me);
        me->set_temp("azhu/yirong2",1);
        return 1;
}
 message_vision(HIC"������ֵ��ʵ������������Щ��ʲô����\n"NOR, me);
        return 1;


}
int ask_yirong3()
{ 
        object me = this_player();
        string msg;
        if (me->query_temp("azhu/yirong2")==1)
        {
        msg = HIY"����˵��:����Ƥ������Ǿ���Ľ�����Ҿ������ƶ��ɡ�\n"NOR;
        msg+= HIY"����˵��:���۽���,��ʶ�����а���Ĳ����������˶��ѡ�\n"NOR;
        msg+= HIY"����˵��:�������ܰ������һ׮��Ը,��Ը�������˫�ַ��ϡ�\n"NOR;
        msg+= HIY"����˵��:�������߽���,Ҳ��Ϊ����ʡȴ��ෳ��,��֪�������?\n"NOR;
        message_vision(msg, me);
        me->set_temp("azhu/yirong3",1);
        return 1;
}
 message_vision(HIC"������ֵ��ʵ������������Щ��ʲô����\n"NOR, me);
        return 1;


}


int ask_help()
{        
        object baofu;
        object me = this_player();
        string msg;
        if (me->query_temp("azhu/yirong3")==1)
        {
        msg = HIY"����˵��:������Ϊ���Ҽҹ���֪��֮��,˽����ɽ����,����������֮��--�׽,�ǵ����´��ҡ�\n"NOR;
        msg+= HIY"����˵��:����ϸϸ����,��ڵ���֮±ç,���°ûڷǳ���\n"NOR;
        msg+= HIY"����˵��:�˷���������,ֻ������´��һ������֣������Ҵ�׮��Ը��\n"NOR;
        msg+= HIY"���콫һ��������������!\n"NOR;
        message_vision(msg, me);
        baofu=new("/d/mr/npc/obj/baofu");
	 baofu->move(this_player());
        me->set_temp("azhu/mask",1);
        return 1;
}
 message_vision(HIC"������ֵ��ʵ������������Щ��ʲô����\n"NOR, me);
        return 1;


}

int accept_object(object me, object obj)
{
        object mask;
        if ((string)obj->query("id")=="xuanci letter") {
        message("vision",me->name()+"������һ�����������ȷ��ɵ��ױ����š�\n",environment(me),
            ({me}));
        mask = unew("/d/mr/npc/obj/mask");
        if (me->query_temp("azhu/mask3") < 1) return notify_fail (CYN"����˵��������������ʲô?\n"NOR); 
        if(!clonep(mask))
                return notify_fail(HIR"�������ˣ���Ƥ����Ѿ�����ȡ���ˡ�\n"NOR);
        if(clonep(mask) && mask->violate_unique()){
                destruct(mask);
                return notify_fail(HIR"�������ˣ���Ƥ����Ѿ�����ȡ���ˡ�\n"NOR);
        }
        command("thank "+me->query("id"));
        command("say ��л"+RANK_D->query_respect(me)+"��СŮ����ȴ��׮��Ը��");
        mask->move(me);        
        message_vision("$n�ݸ�$Nһ����Ƥ��ߡ�\n", me, this_object() );
        CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,�õ�һ��" + HIW + "��Ƥ���" + NOR + "��\n");          
        command("say ����������պ�,������Ҫ�Դ�Ϊ��");
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
        }
        return 0;
}

void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
