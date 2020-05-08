<html>
<head>
	<?php
	include("include/head.html");
	?>
</head>
<body>
	<?php
	include("include/menu.html");
	?>
	<h1 class="title">Проверка на знанията по правопис</h1>

	<div class="topDescription">
	<p>От тук може да проверите знанията си по правопис на български или английски език.
	Системата Ви задава определен брой думи с няколко изписвания, като едното от тях е
	правилно, а останалите грешни. Вашата задача е да познаете кое е правилното изписване на думата.
	Списъкът на думите е съставен на база най-често допусканите грешки от потребителите на
	Словоред. Базата с думи съдържа около 2 500 грешни думи на български език и около 3 000
	на английски език. За информация на редовните посетители на сайта, това е втората версия
	на системата за проверка на знанията по правопис, като разликите с първата са увеличен брой
	думи от 500 до сегашните 2 500 и 3 000. Другата разлика е изписване на няколко грешни варианта
	на думата, ако разбира се има. В предната беше едно правилно значение и само едно грешно.</p>
	</div>

	<form name="spelling" action="random.php" method="POST">
		<table id="testFormTable" summary="Used for layout reasons">
			<tr>
				<td class="right">Правопис:</td>
				<td>
					<select name="testLanguage">
						<option value="1" selected="selected">На български думи</option>
						<option value="2">На английски думи</option>
					</select>
				</td>
			</tr>
			<tr>
				<td class="right">Тест &#8470;:</td>
				<td>
					<select name="testNumber">
						<option value="0" selected="selected">Случаен</option>
						<option>1</option>
						<option>2</option>
						<option>3</option>
						<option>4</option>
						<option>5</option>
						<option>6</option>
						<option>7</option>
						<option>8</option>
						<option>9</option>
						<option>10</option>
						<option>11</option>
						<option>12</option>
						<option>13</option>
						<option>14</option>
						<option>15</option>
						<option>16</option>
						<option>17</option>
						<option>18</option>
						<option>19</option>
						<option>20</option>
						<option>21</option>
						<option>22</option>
						<option>23</option>
						<option>24</option>
						<option>25</option>
						<option>26</option>
						<option>27</option>
						<option>28</option>
						<option>29</option>
						<option>30</option>
						<option>31</option>
						<option>32</option>
						<option>33</option>
						<option>34</option>
						<option>35</option>
						<option>36</option>
						<option>37</option>
						<option>38</option>
						<option>39</option>
						<option>40</option>
						<option>41</option>
						<option>42</option>
						<option>43</option>
						<option>44</option>
						<option>45</option>
						<option>46</option>
						<option>47</option>
						<option>48</option>
						<option>49</option>
						<option>50</option>
						<option>51</option>
						<option>52</option>
						<option>53</option>
						<option>54</option>
						<option>55</option>
						<option>56</option>
						<option>57</option>
						<option>58</option>
						<option>59</option>
						<option>60</option>
						<option>61</option>
						<option>62</option>
						<option>63</option>
						<option>64</option>
						<option>65</option>
						<option>66</option>
						<option>67</option>
						<option>68</option>
						<option>69</option>
						<option>70</option>
						<option>71</option>
						<option>72</option>
						<option>73</option>
						<option>74</option>
						<option>75</option>
						<option>76</option>
						<option>77</option>
						<option>78</option>
						<option>79</option>
						<option>80</option>
						<option>81</option>
						<option>82</option>
						<option>83</option>
						<option>84</option>
						<option>85</option>
						<option>86</option>
						<option>87</option>
						<option>88</option>
						<option>89</option>
						<option>90</option>
						<option>91</option>
						<option>92</option>
						<option>93</option>
						<option>94</option>
						<option>95</option>
						<option>96</option>
						<option>97</option>
						<option>98</option>
						<option>99</option>
						<option>100</option>
					</select>
				</td>
			</tr>
			<tr>
				<td class="right">Брой въпроси:</td>
				<td>
					<select name="testQuestions">
						<option>10</option>
						<option>15</option>
						<option>20</option>
						<option selected="selected">25</option>
						<option>30</option>
						<option>50</option>
						<option>100</option>
					</select>
				</td>
			</tr>
			<tr>
				<td colspan="2"><label title="Автоматично изпращане на отговора без допълнително натискане на бутона Проверка"><input type="checkbox" name="autoSubmit" value="1" checked="checked"/> Без потвърждаване на отговора</label></td>
			</tr>
			<tr>
				<td colspan="2">&nbsp;</td>
			</tr>
			<tr>
				<td class="right" colspan="2">
					<button type="submit" name="start" value="start" title="Стартиране на теста с избраните параметри">Начало на теста</button>
				</td>
			</tr>
		</table>
	</form>
</body>
</html>