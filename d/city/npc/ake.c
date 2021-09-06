// 阿珂

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("阿珂", ({ "a ke", "ake" }));
        set("gender", "女性");
        set("unique", 1);
        set("age", 20);      
	      set("long","正名陈珂，是金庸小说《鹿鼎记》中人物的绝代美女，白玉镶珠不足比其容色、玫瑰初露不能方其清丽，\n"
	      "但阅历浅显，对人性认知甚少。她与阿琪一起寻找师父时，巧遇韦小宝，韦小宝因迷恋她的美色，对她\n"
	      "死缠烂打，但她一直倾心于郑克爽，对韦小宝态度冷淡，并多次险些伤害韦小宝性命。她的身世很惨，\n"
	      "是李自成和陈圆圆之女，小时同母亲居于吴三桂府，后被九难偷走，九难为报国仇家恨，又因误认为她\n"
	      "是吴三桂之女，所以教他刺杀吴三桂。失手后明白了自己的身世，一心希望和郑克爽远走高飞，在扬州\n"
	      "丽春院怀了韦小宝的骨肉，最后随韦小宝归隐。\n");
	      set("str", 20);
        set("int", 20);
        set("con", 18);
        set("dex", 22);
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
	      set("max_qi",100000);
        set("max_jing",100000);
        set("neili",0);
        set("max_neili",0);
	      set("jiali",0);

        set_skill("strike", 60);
	      set_skill("parry",80);
	      set_skill("sword",80);
        set_skill("dodge", 900);
	      set_skill("tiejian-jue",70);

	      map_skill("strike","luoyan-zhang");
	      map_skill("dodge","shenxing-baibian");       

        setup();
     
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt1")->wear();
        set("inquiry", ([ 
 ]));           
}
