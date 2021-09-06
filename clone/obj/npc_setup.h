//Cracked by Kafei
#ifndef _NPC_SETUP_H_
#define _NPC_SETUP_H_

static string *menpai_list = ({
    "huashan", "shaolin", "wudang", "emei", "gaibang",
    "baituo", "xueshan", "xingxiu", "taohua" });

static mixed lastnamelist=({
({"��", "zhao"}), ({"Ǯ", "qian"}),  ({"��", "sun"}),   ({"��", "li"}),
({"��", "zhou"}), ({"��", "wu"}),    ({"֣", "zheng"}), ({"��", "wang"}),
({"��", "feng"}), ({"��", "chen"}),  ({"��", "wei"}),   ({"��", "gao"}),
({"��", "yun"}),  ({"��", "zhang"}), ({"��", "liu"}),   ({"��", "ma"}),
({"��", "yue"}),  ({"��", "cheng"}), ({"��", "he"}),   ({"��", "lin"}),
({"��", "pan"}),  ({"��", "bai"}), ({"��", "xiang"}),   ({"��", "yan"}),
({"��", "fang"}),  ({"��", "yu"}), ({"½", "lu"}),   ({"��", "he"}),
({"��", "meng"}),  ({"л", "xie"}), ({"��", "xu"}),   ({"��", "yang"}),
({"��", "han"}),  ({"��", "peng"}), ({"��", "qiu"}),   ({"��", "yang"}),
({"��", "you"}),  ({"��", "ren"}), ({"��", "xiong"}),   ({"˾��", "sima"}),
({"ɣ", "sang"}),  ({"Ȫ", "quan"}), ({"��", "jin"}),   ({"��", "ding"}),
({"��", "tian"}),  ({"�Ϲ�", "shangguan"}), ({"Ī", "mo"}),   ({"��", "qin"}),
});

static mixed firstnamelist=({
({"����", "jinao"}),   ({"��", "hou"}), ({"��", "ke"}),
({"����", "guoliang"}), ({"���", "guangjie"}), ({"���", "lingjun"}),
({"��", "xuan"}),    ({"����", "wanghai"}),  ({"ǧ��", "qianling"}),
({"��", "qing"}),    ({"��ɽ", "boshan"}),  ({"����", "guangyi"}),
({"����", "daxiong"}),    ({"��", "he"}),  ({"�ż�", "jiujia"}),
({"���", "tianheng"}),    ({"����", "wenliang"}),  ({"����", "jinpeng"}),
({"��", "tao"}),    ({"���", "zecheng"}),  ({"ʯ��", "shijian"}),
({"��", "ping"}),    ({"����", "jiannan"}),  ({"����", "zhenghong"}),
({"���", "tianbiao"}),    ({"һ��", "yimang"}),  ({"̩", "tai"}),
({"��Զ", "zhiyuan"}),    ({"����", "songnian"}),  ({"Ѹ", "xun"}),
({"����", "sanxing"}),    ({"��ͩ", "gutong"}),  ({"��Ӣ", "boying"}),
({"��ͯ", "baitong"}),    ({"��ͤ", "lianting"}),  ({"��", "mian"}),
({"����", "boguang"}),    ({"��", "yun"}),  ({"����", "nanyang"}),
});

void set_random_name();

// sets full status (qi, jing, neili, jingli) according to level
void set_hp(int level);

// random menpai if parameter "menpai" given is 0
// return the menpai this npc has been assigned to
// sets "default_weapon" attribute
string set_skills(string menpai, int exp, int skill_rate);
#endif
