// by fengyue

inherit NPC;
#include <ansi.h>


string* luns = ({
       BINGQI_D("gold-falun"),
       BINGQI_D("silver-falun"),
       BINGQI_D("bronze-falun"),
       BINGQI_D("iron-falun"),
       BINGQI_D("leaden-falun"),
});


void create()
{
        object weapon;
        set_name("���ַ���", ({ "jinlun fawang", "jinlunfawang","fawang" ,"jinlun"}));
        set("long",@LONG
����ĸ��ݣ��������ݣ�˫Ŀ������������̫��Ѩȴ�߸�͹���������ࡣ
���ܷ⡰�ɹŹ���һ��ʦ��������һ��ͨ�쳹�ص��񹦡�
LONG
        );
        set("title", HIY "�ɹŹ���һ��ʦ" NOR);
        set("gender", "����");
        set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 34);
        set("per", 22);

        set("max_qi", 9500);
        set("max_jing", 6500);
        set("eff_jingli", 7500);
        set("neili", 18000);
        set("max_neili", 18000);
        set("jiali", 100);
        set("combat_exp", 4500000);
        set("score", 28000);
        set("unique", 1);

        set_skill("huanxi-chan", 200);
        set_skill("literate", 200);
        set_skill("force", 360);
        set_skill("longxiang-boruo", 360);
        set_skill("dodge", 380);
        set_skill("yuxue-dunxing", 380);
        set_skill("hammer", 380);
        set_skill("xiangfu-lun", 380);
        set_skill("hand", 340);
        set_skill("dashou-yin",340);
        set_skill("claw", 340);
        set_skill("tianwang-zhua", 340);
        set_skill("parry", 360 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hammer", "xiangfu-lun");
        map_skill("parry", "xiangfu-lun");
        map_skill("hand","dashou-yin");
        map_skill("claw","tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("������", 10, "����");
       
        set("lun_count",5);
        set("lun_count2",1);
        set("class", "huanxi");
        set("chat_chance", 2);     
        set("chat_msg", ({
		CYN"���ַ�����Ȼ������ʮ����������������ڻ��ͨ���������������ǵڶ��ˣ�\n"NOR,
		CYN"���ַ����߷ߵĵ�����ԭ���˲�����أ������˶࣬��������һӵ���ϡ�\n"NOR,
		CYN"���ַ����߷ߵĵ�: �ߣ�����ƾ��һ��֮������ȡ����������֮λ��\n"NOR,
	}) );
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "shield jinlun fawang" :),
                (: perform_action, "hammer.wushuai" :), 
	}));

        set_temp("apply/damage", 70);
        set_temp("apply/dodge", 80);
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 60);

        setup();
	if (clonep()){
                weapon = unew(BINGQI_D("gold-falun"));
                if (!weapon) weapon = unew(BINGQI_D("silver-falun"));
                if (!weapon) weapon = unew(BINGQI_D("bronze-falun"));
                if (!weapon) weapon = unew(BINGQI_D("iron-falun"));
                if (!weapon) weapon = unew(BINGQI_D("leaden-falun"));
                weapon->move(this_object());
                weapon->wield();
                carry_object("/d/xueshan/npc/obj/longxiang-jiasha")->wear();       
                add_money("gold",2);
        }
}


 void init()
 {
	object me = this_player();
       	::init();
	if ( me->query_temp("/quest/tzauto/yideng") == 1) {
                command("chat ���˾���ҹ���о����ʣ�ֻ�����������������ˣ� ");
                command("chat* sneer "+me->query("id"));
start_busy(2);
                                kill_ob(me);
		me->fight_ob(this_object());
                me->delete_temp("quest/tzauto/yideng");
                me->set_temp("quest/tzauto/dajiu",1);  
	}
}
 
 void die()

 {
       message_vision("$N�޺޵Ķ���˵��������������󣡡���\n", this_object());
       message_vision("$N��������Ͳ����ˡ�\n", this_object());
       destruct(this_object());
    
}






