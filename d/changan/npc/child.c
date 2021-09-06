// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/child.c

inherit NPC;

string* f_name = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* f_id = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qin","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","bo","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","huo",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"gou","kang","kuang","hou","you","qin","shang","mu","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kuai","zhong","zong",
"lin","shi",
});

string* name_m = ({
"С��","С��","С��","С��","С��","С��","С��",
});

string* id_m = ({
"xiaoer","xiaosan","xiaosi","xiaowu","xiaoliu","xiaoqi","xiaoba",
});

void create()
{
        string f_n, f_i, name_1, id_1;
        int i;
    
        i = random(sizeof(f_name));
        f_n = f_name[i];
        f_i = f_id[i];
        i = random(sizeof(name_m));
        name_1 = name_m[i];
        id_1 = id_m[i];

        set_name(f_n+name_1,({ f_i+" "+id_1, f_i, id_1 }));
        //set_name(name);
        set("gender", "����" );
        set("age", 12);
        set("long", "���Ǹ��ǳ���Ƥ�����İ���ӡ�\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 2000);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");
        setup();

        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 10);
}