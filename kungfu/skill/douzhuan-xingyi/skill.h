// skill.h for /kungfu/skill/douzhuan-xingyi/douzhuanxingyi.c

mapping *perform = ({

// ALL MemPai got 2 symbolically skill ( weapon & unarmed ) here. should modify later
// hs,xx,sl,wd,gb,mj,gm,dl,em,tz,tls,xs,th

// HuaShan

([      "name"        :  "huashan-sanshengfeng",
        "describe"    :  "����һ����Х����������ʹ������������塹��������ػ�����ȭһ����",
        "menpai"      :  "��ɽ��",
        "skill_type"  :  "weapon", // weapon||unarmed
        "weapon_type" :  "sword", // sword,blade,whip...etc
        "unarmed_type":  "none",  // strike,hand,finger,etc
        "perform_type":  "1",
]),

([      "name"        :  "huashan-sanshengfeng",
        "describe"    :  "ʹ����ʯ����ȭ�ľ�ѧ�׶����죬��ʱ��յ���������",
        "menpai"      :  "��ɽ��",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "cuff",
        "perform_type":  "3",
]),

// XingXiu

([      "name"        :  "pixie-jian",
        "describe"    :  "һ����Ц������һ�ź��ư��������������ϸ�뼲ָ˫Ŀ��",
        "menpai"      :  "������",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "2",
]),

([      "name"        :  "chousui-zhang",
        "describe"    :  "��¶����֮ɫ��˫��ɫ�����ϣ�ԭ��������Ʒ羹���������Ϣ��",
        "menpai"      :  "������",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),

// ShaoLin

([      "name"        :  "jinggang-quan",
        "describe"    :  "ʹ�����±޷������ơ������������ޣ�ɢ�������������ͼ�ѵ�ȫ�����������",
        "menpai"      :  "������",
        "skill_type"  :  "weapon",
        "weapon_type" :  "whip",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "jinggang-quan",
        "describe"    :  "ͻȻȫ��������죬�����Ԫһ������ȫ�������ʹ���������һ����",
        "menpai"      :  "������",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "3",
]),

// WuDang

([      "name"        :  "taiji-jian",
        "describe"    :  "ʹ��̫�������������־�����������������ͼ���ҶԷ��Ĺ��ơ�",
        "menpai"      :  "�䵱��",
        "skill_type"  :  "weapon",
        "weapon_type" :  "none",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "taiji-quan",
        "describe"    :  "һ��һʽ�ڽڹᴮ���糤����ӣ���ճ���־�һ��ʹ����һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ���������಻�ϣ����ϲ���",
        "menpai"      :  "�䵱��",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "cuff",
        "perform_type":  "4",
]),

// GaiBang

([      "name"        :  "dagou-bangfa",
        "describe"    :  "ʹ���򹷰��������֡�����ֻ��һ����Ӱ����ǵ����˹�ȥ ",
        "menpai"      :  "ؤ��",
        "skill_type"  :  "weapon",
        "weapon_type" :  "stick",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "xianglong-zhang",
        "describe"    :  "һ���Ϻȣ�˫�������Ю�������ɳ��ʹ����������ĵ��⹦������˫�ơ���",
        "menpai"      :  "ؤ��",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),

// MinJiao

([      "name"        :  "yinfeng-dao",
        "describe"    :  "����ʹ�����絶������һ���������ʵ�����֮����ֱ��ҪѨ��ȥ��",
        "menpai"      :  "����",
        "skill_type"  :  "weapon",
        "weapon_type" :  "blade",
        "unarmed_type":  "none",
        "perform_type":  "5",
]),

([      "name"        :  "hanbing-mianzhang",
        "describe"    :  "ͻȻ��ͬһֻ��Ѫ���������ȥ����������ʺ�ҧȥ��",
        "menpai"      :  "����",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "bite",
        "perform_type":  "5",
]),

// GuMu

([      "name"        :  "xuantie-jianfa",
        "describe"    :  "���һ�����ֳ�������Ю���˳�ӿ֮��,������죬������ᣬ����Ȼ�����������֮���������ߴΣ�ϯ���ȥ��",
        "menpai"      :  "��Ĺ��",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "1",
]),

([      "name"        :  "anran-zhang",
        "describe"    :  "������֮ɫ�����������ң�û����ɵĻ����������ĳ�һ��",
        "menpai"      :  "��Ĺ��",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),

// DaLi

([      "name"        :  "duanjia-jianfa",
        "describe"    :  "��Цһ�����������֣�������ϣ�ʩչ�������Ļ�����������ͼ���ٻ��˶��֡�",
        "menpai"      :  "�����",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "1",
]),

([      "name"        :  "yiyang-zhi",
        "describe"    :  "������ָ��һʽ���������������ֻ������������ָ������������",
        "menpai"      :  "�����",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "finger",
        "perform_type":  "5",
]),

// Emei

([      "name"        :  "huifeng-jianfa",
        "describe"    :  "��Хһ���������ڿ����������Ҿ������𽣡��ķ�����ط��������֮�У�������������������",
        "menpai"      :  "������",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "3",
]),

([      "name"        :  "jieshou-jiushi",
        "describe"    :  "����ׯ�ϣ���ת�����ټ�ʮ��ׯ����һ��������Ʈ����ϣ���������ƽ���һɲ��֮�䣬һ���ھ����������ˣ������������Ƶ�����",
        "menpai"      :  "������",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "hand",
        "perform_type":  "5",
]),

// TianLongSi

([      "name"        :  "duanjia-jianfa",
        "describe"    :  "��Цһ�����������֣�������ϣ�ʩչ�������Ļ�����������ͼ���ٻ��˶��֡�",
        "menpai"      :  "������",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "1",
]),

([      "name"        :  "yiyang-zhi",
        "describe"    :  "������ָ��һʽ���������������ֻ������������ָ������������",
        "menpai"      :  "������",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "finger",
        "perform_type":  "5",
]),

// XueShan
/*
([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "������",
        "skill_type"  :  "weapon",
        "weapon_type" :  "",
        "unarmed_type":  "none",
        "perform_type":  "",
]),

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "������",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "",
        "perform_type":  "",
]),

// TieZhang

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "",
        "skill_type"  :  "weapon",
        "weapon_type" :  "",
        "unarmed_type":  "none",
        "perform_type":  "",
]),

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "",
        "perform_type":  "",
]),
*/
// TaoHua

([      "name"        :  "yuxiao-jianfa",
        "describe"    :  "����յ���ߣ��������£�����Ͳ��ͻȻ���һ����⣬���ɶ�ȥ��",
        "menpai"      :  "�һ���",
        "skill_type"  :  "weapon",
        "weapon_type" :  "xiao",
        "unarmed_type":  "none",
        "perform_type":  "5",
]),

([      "name"        :  "luoying-zhang",
        "describe"    :  "˫��������Ե���ƽ��棬��Ȼ����˿˿�Ľ��������������߷��ϻ�",
        "menpai"      :  "�һ���",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),
// Shen long dao
([      "name"        :  "canglang-goufa",
        "describe"    :  "������������֮����ƴ��ȫ��ʹ�����������֮����������Ӣ�����С�",
        "menpai"      :  "������",
        "skill_type"  :  "weapon",
        "weapon_type" :  "hook",
        "unarmed_type":  "leg",
        "perform_type":  "1",
]),
([      "name"        :  "huagu-mianzhang",
        "describe"    :  "��Ȼ��һ������˫��һ��������������ĳ���",
        "menpai"      :  "������",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "1",
]),

// Other        

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "",
        "skill_type"  :  "",
        "weapon_type" :  "",
        "unarmed_type":  "",
        "perform_type":  "",
]),

});
